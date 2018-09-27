//
// Created by ferathor on 18/09/18.
//

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

template <typename T>

class MPointer {
public:
    MPointer();
    MPointer(T nVal);
    T operator*();
    void operator*(T nVal);
    int* operator&();
    void operator&(int* nPtr);
    void operator=(T nVal);
private:
    T* val;
    int* ptr;
};


#endif //MPOINTER_MPOINTER_H
