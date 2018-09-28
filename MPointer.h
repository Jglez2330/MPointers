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
//    MPointer<T> New();
    T operator*();
    void operator*(T nVal);
    int* operator&();
    void operator&(int* nPtr);
    void operator=(T nVal);
    void operator=(MPointer<T> nPtr);
    void erase();
private:
    T* val;
    int* ptr;
    bool fVal;
};


#endif //MPOINTER_MPOINTER_H
