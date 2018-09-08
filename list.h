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
            return *this->begin();
          }
        };
        T back(){
          if (!this->start) {
            throw("empty list");
          }else{
            return *this->end();
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
            temp = nullptr; // Esto está de más, no es necesario. Igual que la siguiente línea
            delete temp;
            this->nodes++;
        };
        void push_back(T value){
          Node<T> *temp = new Node<T> {value, nullptr, nullptr};
          if (!this->start) {
            temp->next = temp;
            temp->prev = temp;
            this->start = temp;
          }else{
            temp->next = this->start;
            temp->prev = this->start->prev;
            this->start->prev->next = temp;
            this->start->prev = temp;
          }
          temp = nullptr; // Esto está de más, no es necesario. Igual que la siguiente línea
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
        T get(int position){
          Iterator<T> current = this->begin();
          for (int i = 0; i < position; i++, ++current){}
          return *current;
        };
        void concat(List<T> &other){
          Node<T>* temp = other.start->prev;
          other.start->prev->next = this->start;
          this->start->prev->next = other.start;
          other.start->prev = this->start->prev;
          this->start->prev = temp;
          temp = nullptr; // Esto está de más, no es necesario. Igual que la siguiente línea
          delete temp;
          this->nodes += other.nodes;
          other.start = nullptr;
          delete other.start; // Esto está de más, no es necesario. Igual que la siguiente línea
        };
        bool empty(){return !this->start;};
        int size(){return this->nodes;};
        void clear(){
          this->start->killSelf(this->start);
          this->nodes=0;
          this->start=nullptr;
        };
        Iterator<T> begin(){return Iterator<T> (this->start);};
        Iterator<T> end(){return Iterator <T> (this->start->prev);};

      ~List(){
          if (this->start) {
            this->start->killSelf(this->start);
            this->nodes=0;
            this->start=nullptr;
            delete this->start;
          }
        };
};

#endif
