//
// Created by Joseph Luis González Pastora on 24/9/18.
//

#ifndef MPOINTERS_SERVERMEMORYMANAGEMENT_H
#define MPOINTERS_SERVERMEMORYMANAGEMENT_H


#include <cstddef>
#include "nlohmann/json.hpp"
using json = nlohmann::json;
class ServerMemoryManagement {
public:
    int requestMemory(size_t size);
    void getValue(int ID);
    void saveValue(json Value);
    



private:
    void* memeryBlock;

};


#endif //MPOINTERS_SERVERMEMORYMANAGEMENT_H
