//
// Created by ferathor on 27/09/18.
//

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
#include <thread>
#include "Socket.h"
//#include "LinkedList.h"
//#include "LinkedList.cpp"
#include "ServerMemoryManagement.h"

int main() {



std::thread socketServer(ServerSocket::getInstance);


socketServer.join();

    return 0;
}
