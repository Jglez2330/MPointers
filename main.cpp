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
#include "Socket.h"
//#include "LinkedList.h"
//#include "LinkedList.cpp"
#include "ServerMemoryManagement.h"

int main() {

    ServerSocket* socket = ServerSocket::getInstance();
    ServerSocket* socket2 = ServerSocket::getInstance();

    std::cout << &*socket<<std::endl;
    std::cout << &*socket2<<std::endl;*/
    /*LinkedList<int> *list = new LinkedList<int>();
    list->add(101);
    list->add(102);
    list->add(103);
    list->remove(1);
    std::cout << list->get(2);*/
    ServerMemoryManagement* management = new ServerMemoryManagement();
    management->requestMemory(sizeof(int)*5);
    json j = {{"Data", 0}};
    json j2 = {{"Data", 1}};
    management->saveValue(j);
    management->saveValue(j2);
    return 0;
}