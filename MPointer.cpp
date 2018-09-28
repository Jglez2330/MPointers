//
// Created by ferathor on 18/09/18.
//

#include "MPointer.h"
#include <cstdlib>
#include <iostream>

template <typename T>
MPointer<T>::MPointer() {
    this->fVal = false;
    this->ptr = (int*) malloc(sizeof(this));
}

template <typename T>
MPointer<T>::MPointer(T nVal) {
    this->val = (T*) malloc(sizeof(T));
    *this->val = nVal;
    this->fVal = true;
    this->ptr = (int*) malloc(sizeof(this));
}

//template <typename T>
//MPointer<T>::MPointer<T> New() {
//    MPointer<T> mPtr = MPointer<T>::MPointer();
//    return mPtr;
//}

template <typename T>
T MPointer<T>::operator*() {
    if(this->fVal) {
        return *this->val;
    } else {
        std::cout << "This pointer was released. The value saved in the pointer now is: ";
    }
}

template <typename T>
void MPointer<T>::operator*(T nVal) {
    if(!this->fVal) {
        this->val = (T*) malloc(sizeof(T));
        *this->val = nVal;
        this->fVal = true;
    } else {
        *this->val = nVal;
    }
}

template <typename T>
int* MPointer<T>::operator&() {
    return this->ptr;
}

template <typename T>
void MPointer<T>::operator&(int *nPtr) {
    this->ptr = nPtr;
}

template <typename T>
void MPointer<T>::operator=(T nVal) {
    if(!this->fVal) {
        this->val = (T*) malloc(sizeof(T));
        *this->val = nVal;
        this->fVAl = true;
    } else {
        *this->val = nVal;
    }
}

template <typename T>
void MPointer<T>::operator=(MPointer<T> nPtr) {
    if(!this->fVal) {
        this->val = (T*) malloc(sizeof(T));
        *this->val = nPtr.operator*();
        this->fVAl = true;
    } else {
        *this->val = nPtr.operator*();
    }
}

template <typename T>
void MPointer<T>::erase() {
    if(this->fVal) {
        free(this->val);
        this->fVal = false;
    }
}