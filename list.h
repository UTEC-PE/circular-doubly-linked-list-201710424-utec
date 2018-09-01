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
        int nodes = 0;

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
          Node<T> *temp = new  Node<T> {value, nullptr, nullptr};
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
            temp = nullptr;
            delete temp;
            this->nodes++;
        };
        void push_back(T value){
          Node<T> *temp = new Node<T> {value, nullptr, nullptr};
          if (!this->start) {
            temp->next = temp;
            temp->prev = temp;
          }else{
            temp->next = this->start;
            temp->prev = this->start->prev;
            this->start->prev->next = temp;
            this->start->prev = temp;
          }
          temp = nullptr;
          delete temp;
          this->nodes++;
        };
        void pop_front(){
          if (!this->start) {
            throw("empty list");
          }else if (this->start->next==this->start) {
            delete this->start;
            this->start = nullptr;
          }else{
            this->start = this->start->next;
            this->start->prev = this->start->prev->prev;
            delete this->start->prev->next;
            this->start->prev->next = this->start;
          }
          this->nodes--;
        };
        void pop_back(){
          if (!this->start) {
            throw("empty list");
          }else if (this->start->next==this->start) {
            delete this->start;
            this->start = nullptr;
          }else{
            this->start->prev = this->start->prev->prev;
            delete this->start->prev->next;
            this->start->prev->next = this->start;
          }
          this->nodes--;
        };
        T get(int position);
        void concat(List<T> &other){
          
        };
        bool empty(){return !this->start;};
        int size(){return this->nodes;};
        void clear(){

        };
        Iterator<T> begin();
        Iterator<T> end();

        //~List();
};

#endif
