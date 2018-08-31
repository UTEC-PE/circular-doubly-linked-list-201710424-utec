#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;

    public:
        List(){
          this->start = nullptr;
        };

        T front(){
          if(!this->start){
            throw("empty list");
          }else{
            return this->start->data;
          }
        };
        T back(){
          if (!this->start) {
            throw("empty list");
          }else{
            return this->start->prev->data;
          }
        };
        void push_front(T value){
          Node<T> *temp = New  Node<T> {value, nullptr, nullptr};
          if (!this->start) {
            temp->next = temp;
            temp->prev = temp;
          }else{
            temp->next = this->start;
            temp->prev = this->start->prev;
            this->start->prev->next = temp;
            this->start->prev = temp;
          }
            this->start = temp;
        };
        void push_back(T value);
        void pop_front();
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();

        ~List();
};

#endif
