//
// Created by Joseph Luis González Pastora on 24/9/18.
//

#include <cstdlib>
#include "ServerMemoryManagement.h"

int ServerMemoryManagement::requestMemory(size_t size) {
    this->memeryBlock = malloc(size);

    return 0;
}

void ServerMemoryManagement::getValue(int ID) {


}

void ServerMemoryManagement::saveValue(json Value) {


}
