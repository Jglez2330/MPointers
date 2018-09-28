//
// Created by Joseph Luis González Pastora on 24/9/18.
//

#include <cstdlib>
#include "ServerMemoryManagement.h"

int ServerMemoryManagement::requestMemory(int size) {
    this->memeryBlock = (int *)malloc(sizeof(int)*size);
    this->size = size;
    this->lista = nullptr;

    return 0;
}

void ServerMemoryManagement::getValue(int ID) {
    if (ID > size-1){
        exit(-1);
    }else{

        for (int i = 0; i < lista.)

    }


}

void ServerMemoryManagement::saveValue(json Value) {






}
