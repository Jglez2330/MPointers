//
// Created by Joseph Luis González Pastora on 24/8/18.
//

#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
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
    SocketAddressIn serv_addr;
    SocketAddressIn client_addr;
    this->serverSocket = socket(AF_INET,SOCK_STREAM,0);
    if (this->serverSocket < 0){
        std::cout << "Error"<< std::endl;
    }
    bzero((char*)&serv_addr, sizeof(serv_addr));

    this->portNumber = atoi("5555");

    serv_addr.socketInProtocol = AF_INET;
    serv_addr.socketInAddress.socketAddress = INADDR_ANY;
    serv_addr.socketInPort = htons(this->portNumber);
    if (bind(serverSocket,(struct SocketAddressIn*)&serv_addr, sizeof(serv_addr))){
        error("Error binding");
    }


}
