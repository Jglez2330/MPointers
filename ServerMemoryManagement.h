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

    nlohmann::json getValue(int ID);
    void remove(int ID);
    void changeValue(int ID, json Value);
    nlohmann::json saveValue(json Value);
    void printMemory();
    



private:
    int* memeryBlock;
    int size;
    LinkedList<int> *lista;

    bool isFull();

    bool hasID(int id);
};


#endif //MPOINTERS_SERVERMEMORYMANAGEMENT_H
