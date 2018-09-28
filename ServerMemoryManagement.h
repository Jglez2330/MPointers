//
// Created by Joseph Luis González Pastora on 24/9/18.
//

#ifndef MPOINTERS_SERVERMEMORYMANAGEMENT_H
#define MPOINTERS_SERVERMEMORYMANAGEMENT_H


#include <cstddef>
#include "json.hpp"

#include "LinkedList.h"
#include "LinkedList.cpp"
using json = nlohmann::json;
class ServerMemoryManagement {
public:
    int requestMemory(int size);

    void getValue(int ID);
    void saveValue(json Value);
    



private:
    int* memeryBlock;
    int size;
    LinkedList<int> *lista;

};


#endif //MPOINTERS_SERVERMEMORYMANAGEMENT_H
