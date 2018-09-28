//
// Created by Joseph Luis González Pastora on 26/9/18.
//

#include "Node.h"

template<typename T>
Node<T> *Node<T>::getNext() const {
    return next;
}

template<typename T>
T* Node<T>::getData() const {
    return data;
}

template<typename T>
int Node<T>::getId() const {
    return id;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) {
    Node::next = next;
}

template<typename T>
void Node<T>::setData(T* data) {
    Node::data = data;
}

template<typename T>
Node<T>::Node(T* data):data(data) {
    this->setNext(nullptr);
    this->data = data;
}

template<typename T>
Node<T>::~Node() {
    free(next);


}
