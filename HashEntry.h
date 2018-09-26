//
// Created by Joseph Luis González Pastora on 23/9/18.
//

#ifndef MPOINTERS_HASHENTRY_H
#define MPOINTERS_HASHENTRY_H


#include <string>

enum Types {Integer = 0x0000, Float = 0x0001, Long = 0x0002, Short = 0x0003, Boolean = 0x0004,Char = 0x0005};

class HashEntry {

private:
    int key;
    Types data;
public:
    HashEntry(int key, Types data);

    std::string getKey();
    Types getData();



};


#endif //MPOINTERS_HASHENTRY_H
