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
    ServerMemoryManagement *management = new ServerMemoryManagement();
    management->requestMemory(5);
    json j = {{"Data", 100}};
    json j2 = {{"Data", 12}};
    json j3 = {{"Data", 13}};
    json j4 = {{"Data", 14}};
    json j5 = {{"Data", 15}};
    json j6 = {{"Data", 16}};
    management->saveValue(j);
    management->saveValue(j2);
    management->saveValue(j3);
    management->saveValue(j4);
    management->saveValue(j5);
    management->changeValue(0,j6);
    //management->saveValue(j6);
    std::cout <<management->getValue(0)["Data"];
    return 0;
}
