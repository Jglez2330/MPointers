//
// Created by Joseph Luis González Pastora on 24/8/18.
//

#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <thread>
#include "Socket.h"


ServerSocket* ServerSocket::serverSocketInstancePTR = nullptr;

void ServerSocket::error(char *error) {
    perror(error);
    exit(1);


}

ServerSocket * ServerSocket::getInstance() {
    if (ServerSocket::serverSocketInstancePTR == nullptr){
        ServerSocket::serverSocketInstancePTR = new ServerSocket();
    }
    return ServerSocket::serverSocketInstancePTR;

}


ServerSocket::ServerSocket() {
    //Crea un socket de tipo AF_INET, con un stream de datos
    this->serverSocket = socket(AF_INET,SOCK_STREAM,0);
    //bzero((char *)&serverSocket, sizeof(serverSocket));
    this->portNumber = atoi("5555");
    //Asigna variables del socket y el tipo
    this->serverAdress.sin_family = AF_INET;
    this->serverAdress.sin_addr.s_addr = INADDR_ANY;
    this->serverAdress.sin_port = htons(this->portNumber);
    //Relaciona el socket con un puerto en la tarjeta de red de la computadora
    bind(serverSocket,(struct sockaddr*)&serverAdress, sizeof(serverAdress));





//Acepta el cliente,
    listen(serverSocket,5);
    this->clientLenght = sizeof(this->clientAdress);
    this->client = accept(this->serverSocket,(struct sockaddr*)&clientAdress,&clientLenght);
    std::cout<< this->clientAdress.sin_port<< std::endl;
    this->memoryManager = new ServerMemoryManagement();


    std::thread listeningClients(&ServerSocket::listenClient,this);
    listeningClients.join();

}


std::string ServerSocket::readClient() {

    bzero(buffer, sizeof(buffer));

    int n = read(this->client,this->buffer, 256);
    std::string bufferString(buffer);

    if (n == 0){
        bufferString ="{\"opcode\":-256}";
    }

    return bufferString;






}

void ServerSocket::listenClient() {
    bool isActive = true;
    json jsonClient;
    while (isActive) {


            std::string clientRequest = readClient();

        try {
            jsonClient = json::parse(clientRequest);
        }catch (...){}

            if ((int )jsonClient["opcode"] == 0) {

                this->memoryManager->requestMemory(jsonClient["size"]);


            } else if ((int) jsonClient["opcode"] == 1) {

                json id =this->memoryManager->saveValue(jsonClient);
                write(this->client,id.dump().data(),256);

            }else if (jsonClient["opcode"] == -256){

                break;

            } else if (jsonClient["opcode"] == 2){

                json value = this->memoryManager->getValue(jsonClient["id"]);
                write(this->client,value.dump().data(),256);


            } else if (jsonClient["opcode"] == 3){

                this->memoryManager->changeValue(jsonClient["id"],jsonClient);

            } else if (jsonClient["opcode"] == 4){

                this->memoryManager->remove(jsonClient["id"]);
            }
            jsonClient = {{"opcode", -1}};

    }






}




