//
// Created by ferathor on 18/09/18.
//

#include "MPointer.h"
#include <cstdlib>
#include <iostream>

template <typename T>
MPointer<T>::MPointer() {
    this->val = (T*) malloc(sizeof(T));
    this->ptr = (int*) malloc(sizeof(this));
}

template <typename T>
MPointer<T>::MPointer(T nVal) {
    this->val = (T*) malloc(sizeof(T));
    *this->val = nVal;
    this->ptr = (int*) malloc(sizeof(this));
}

template <typename T>
MPointer<T> New() {
    MPointer<T> mPtr = MPointer<T>::MPointer();
    return mPtr;
}
template <typename T>
T MPointer<T>::operator*() {
    return *this->val;
}

template <typename T>
void MPointer<T>::operator*(T nVal) {
    *this->val = nVal;
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
    *this->val = nVal;
}