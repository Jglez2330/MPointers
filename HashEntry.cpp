//
// Created by Joseph Luis González Pastora on 23/9/18.
//

#include "HashEntry.h"

HashEntry::HashEntry(int key, Types data) {
    this->data = data;
    this->key = key;

}

std::string HashEntry::getKey() {
    return this->key;
}

Types HashEntry::getData() {
    return this->data;
}
