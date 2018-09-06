#include <iostream>
#include "Socket.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    ServerSocket* socket = ServerSocket::getInstance();
    ServerSocket* socket2 = ServerSocket::getInstance();
    std::cout << &*socket<<std::endl;
    std::cout << &*socket2<<std::endl;

    return 0;
}