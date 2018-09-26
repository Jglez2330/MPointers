#include <iostream>
//#include "Socket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Socket.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    ServerSocket* socket = ServerSocket::getInstance();
    ServerSocket* socket2 = ServerSocket::getInstance();

    std::cout << &*socket<<std::endl;
    std::cout << &*socket2<<std::endl;

    return 0;
}
