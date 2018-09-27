//
// Created by Joseph Luis González Pastora on 26/9/18.
//

#ifndef MPOINTERS_NODE_H
#define MPOINTERS_NODE_H

template <typename T>
class Node {
public:
    Node(T data);

    Node<T> *getNext() const;

    T getData() const;

    int getId() const;

    void setNext(Node<T> *next);

    void setData(T data);

    virtual ~Node();

private:
    Node<T> * next;
    T data;
    int id;
    int offset;
    int lenght;

};


#endif //MPOINTERS_NODE_H
