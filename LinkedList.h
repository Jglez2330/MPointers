//
// Created by Joseph Luis González Pastora on 26/9/18.
//

#ifndef MPOINTERS_LINKEDLIST_H
#define MPOINTERS_LINKEDLIST_H


#include "Node.h"
#include "Node.cpp"
class List{};

template <typename T>
class LinkedList: public List {
private:
    Node<T>* head;
    int length;
public:
    LinkedList();

    void add(T* data);
    T* get(int index);
    void remove(int index);
    T* operator[](int index);

    Node<T> *getHead() const;


};


#endif //MPOINTERS_LINKEDLIST_H
