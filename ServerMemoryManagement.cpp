//
// Created by Joseph Luis González Pastora on 24/9/18.
//

#include <iostream>
#include "ServerMemoryManagement.h"
#include "json.hpp"


int ServerMemoryManagement::requestMemory(int size) {
    this->memeryBlock = (int *)malloc(sizeof(int)*size);
    this->size = size;
    this->lista = nullptr;

    return 0;
}

nlohmann::json ServerMemoryManagement::getValue(int ID) {
    if (ID > size){
        exit(-1);
    }
    else if(!hasID(ID)){
        nlohmann::json json;
        json = {{"Data","Unvalid ID"}};
        return json;

    } else{
        nlohmann::json json;


        for (int i = 0; i < lista->getLength(); i++){
            if (lista->getNode(i)->getId() == ID){
                json = {{"Data",memeryBlock[i]}};
                break;

            }
        }
        return json;

    }


}

nlohmann::json ServerMemoryManagement::saveValue(json Value) {

        if (lista == nullptr) {
            nlohmann::json ID;
            lista = new LinkedList<int>();
            for (int i = 0; i < size; i++) {
                lista->add(nullptr);
            }
            memeryBlock[0] = Value["Data"];

            lista->getNode(0)->setData(&memeryBlock[0]);
            lista->getNode(0)->setId(0);
            ID = {{"ID",lista->getNode(0)->getId()}};
            return ID;
        } else {
            nlohmann::json ID;
            for (int i = 0; i < size; i++) {
                if (lista->get(i) == nullptr) {
                    memeryBlock[i] = Value["Data"];
                    lista->getNode(i)->setData(&memeryBlock[i]);
                    lista->getNode(i)->setId(i);
                    ID = {{"ID", lista->getNode(i)->getId()}};
                    break;


                }
            }
            printMemory();
            return ID;

        }
}



bool ServerMemoryManagement::isFull() {
    bool full = true;
    if (this->lista != nullptr) {
        for (int i = 0; i < size - 1; ++i) {
            if (lista->get(i) == nullptr) {
                full = false;
                break;
            }
        }
    }
    return full;
}

void ServerMemoryManagement::remove(int ID) {
    nlohmann::json removeJson;
    if (ID > size) {
        exit(-1);
    } else {

        for (int i = 0; i < lista->getLength() ; i++) {
            if (lista->getNode(i)->getId() == ID) {
                lista->getNode(i)->setData(nullptr);
                break;

            }
        }
        printMemory();

        return;


    }
}

void ServerMemoryManagement::changeValue(int ID, nlohmann:: json Value) {



        for (int i = 0; i < lista->getLength(); i++){
            if (lista->getNode(i)->getId() == ID){
                memeryBlock[i] = Value["Data"];
                break;

            }
        }
        printMemory();
        return;



    }

bool ServerMemoryManagement::hasID(int id) {
    bool hasId = false;
    if (this->lista != nullptr) {
        for (int i = 0; i < size; i++) {
            if (lista->getNode(i)->getId() == id  && lista->getNode(i)->getData() != nullptr) {
                hasId = true;
                break;
            }
        }
    }
    return hasId;
}

void ServerMemoryManagement::printMemory() {
    printf("%-10s %-10s %-10s %-10s \n \n","i","ID","Value","MemeryDirection");

    for (int i = 0; i < size; ++i) {
        if (lista->get(i) == nullptr){

            printf("%-10s %-10s %-10s %-10s \n","-","-","-","-");

        } else{
            printf("%-10i %-10i %-10i %-#10x \n",i,lista->getNode(i)->getId(),memeryBlock[i],lista->get(i));
        }

    }


}
