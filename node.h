#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;

    void killSelf(Node<T> *start_ptr){
      if (this->next!=start_ptr) {
        this->next->killSelf(start_ptr);
      }
      delete this;
    };
};

#endif
