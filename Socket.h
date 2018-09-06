//
// Created by Joseph Luis González Pastora on 24/8/18.
//
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>


#ifndef MPOINTERS_SOCKET_H
#define MPOINTERS_SOCKET_H



class Socket {
protected:
    /*struct HostInfo{
        char *hostName;
        char **hosrAliases;
        int hostAddressType;
        int hostLength;
        char **hostAddressList;
        #define hostAddress hostAddressList[0];
    };
    //
    struct SocketAddress{
        unsigned short socketAddressProtocol;
        char socketAddressData[14];

    };
    //
    struct InAddress{
        unsigned long socketAddress;
    };

    //
    struct SocketAddressIn{
        short int socketInProtocol;
        unsigned short int socketInPort;
        struct InAddress socketInAddress;
        unsigned char socketInZero[8];
    };*/
    sockaddr_in serverAdress;
    sockaddr_in clientAdress;
    socklen_t clientLenght;
    char buffer[256];


    //Constrcuctor privado, para que no se instancie
Socket(){};




};

//class SocketClient:Socket;
typedef class T;
class ServerSocket : Socket{
public:
    //int bind(int socket, struct SocketAddressIn* local_Address,socklen_t addr_length);
    //void listen();
    //void accept();
    //void send(T data);
    void error(char *error);
    static ServerSocket* getInstance();


private:
    //SocketClient client;
    int serverSocket;
    int portNumber;
    int client;
    static ServerSocket* serverSocketInstancePTR;
    ServerSocket(ServerSocket const&){};
    ServerSocket&operator = (ServerSocket const&){};



  ServerSocket();


};



#endif //MPOINTERS_SOCKET_H
