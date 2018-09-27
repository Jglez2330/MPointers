//
// Created by Joseph Luis González Pastora on 26/9/18.
//

#include <stdexcept>
#include "LinkedList.h"


template<typename T>
void LinkedList<T>::add(T data) {
    Node<T> *node = this->head;
    if (node == nullptr){
        this->head = new Node<T>(data);
        this->length++;
    } else{
        while (node != nullptr){
            if (node->getNext() == nullptr){
                node->setNext(new Node<T>(data));
                this->length++;
                break;
            }
            node = node->getNext();

        }
    }


}

template<typename T>
T LinkedList<T>::get(int index) {
    Node<T> * node = this->head;

    if (length <= index || index < 0){
        throw std::runtime_error("Index out of Boundary");

    }else{
        int internalIndex = 0;
        while (node != nullptr){
            if (internalIndex == index){
                break;
            }
            node = node->getNext();
            internalIndex++;
        }
    }

    return node->getData();

}

template<typename T>
void LinkedList<T>::remove(int index) {

    Node<T> * node = this->head;

    if (length < index || index < 0){
        throw std::runtime_error("Index out of Boundary");

    }else {
        int internalIndex = 0;
        while (node != nullptr) {
            if (index == 0){
                this->head = node->getNext();
                length--;
                free(node);
                break;
            }
            else if (internalIndex+ 1 == index) {
                Node<T> *tmp = node;
                if(node->getNext() == nullptr){
                    tmp->setNext(nullptr);
                } else {
                    tmp->setNext(node->getNext()->getNext());
                }
                //~*node;
                length--;
                break;
            }

            node = node->getNext();
            internalIndex++;
        }
    }
}

template<typename T>
T LinkedList<T>::operator[](int index) {

    Node<T> * node = this->head;

    if (length < index || index < 0){
        throw std::runtime_error("Index out of Boundary");

    }else{
        int internalIndex = 0;
        while (node != nullptr){
            if (internalIndex == index){
                break;
            }
            node = node->getNext();
            internalIndex++;
        }
    }

    return node->getData();
}

template<typename T>
LinkedList<T>::LinkedList():head(nullptr), length(0){
    this->head = nullptr;
    this->length = 0;
}
