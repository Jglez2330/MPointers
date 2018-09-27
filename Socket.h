//
// Created by Joseph Luis González Pastora on 24/8/18.
//
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include "json.hpp"

using json = nlohmann::json;

#ifndef MPOINTERS_SOCKET_H
#define MPOINTERS_SOCKET_H



class Socket {
protected:
    unsigned char socketInZero[8];

    sockaddr_in serverAdress;
    sockaddr_in clientAdress;
    socklen_t clientLenght;
    char buffer[256];
    //Construcctor privado, para que no se instancie
    Socket(){};




};

//class SocketClient:Socket;

class ServerSocket : Socket{
public:
    //void listen();
    //void accept();
    //void send(T data);
    void error(char *error);
    static ServerSocket* getInstance();
    std::string readClient();
    void listenClient();
    void requestMemory(ssize_t size);



private:
    //SocketClient client;
    int serverSocket;
    int portNumber;
    int client;
    static ServerSocket* serverSocketInstancePTR;
    ServerSocket(ServerSocket const&){};
    //ServerSocket&operator = (ServerSocket const&){};
    void *memoryBlock;



  ServerSocket();



    char *split(char *ToSplit, char Delimeter);
};



#endif //MPOINTERS_SOCKET_H
