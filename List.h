/*
 * Name:
 * Date Submitted:
 * Lab Section:
 * Assignment Name:
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
    mySize = 0;
    Node<T>* start = new Node<T>(0);
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
    Node<T> * iterator = start;

    while(iterator != nullptr){
      Node<T>* temp = iterator;
      iterator = iterator->next;
      delete(temp);
    }
}

//Return the size of this list
template <class T>
int List<T>::size(){
    return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
    if (mySize == 0) return 1;
    else return 0;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
    Node<T>* insert = new Node<T>(value);
    start->value = insert->value;
    start->next = nullptr;
    mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node<T>* insert = new Node<T>(value);
  Node<T>* iterator = start;
  Node<T> *Next;

    for (int i = 0; i < mySize-1; i++){
      iterator = iterator->next;
      Next = iterator->next;
    }
    insert->next = Next;
    iterator->next = insert;
    
  mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  Node<T>* insert = new Node<T>(value);
  Node<T>* iterator = start;
  Node<T> *Next;
    for(int i = 0; i < j; i++){
        Next = iterator->next;
        if (i+1 == j) break;
        else iterator = Next;
    }
  insert->next = Next;
  iterator->next = insert;
  mySize++;
    
}
/*
//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
}

*/
