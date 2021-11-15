#include <iostream>
using namespace std;
#include "miniDList.h"
#ifndef MINISTACK_h
#define MINISTACK_h
template <class DataType>
class miniListStack{
private:
miniDList<DataType> list;
public:
miniListStack(); // Constructor for ListStack
miniListStack(const miniListStack &l); // Copy contstructor
~miniListStack(); // Destructor
miniDList<DataType> getList();
int size() const; // get the number of elements in the stack
bool isEmpty() const; // Check if the stack is empty
const DataType& top() const; //get the top emement without popping it
void push(const DataType &e); // Pushes an object onto the stack
void pop(); // Pop an object off the stack
void printStack() const; // Prints the stack from the top, down 3
miniListStack<DataType>& operator=(const miniListStack<DataType> &l); // Assignment operator
};

template <class DataType>
class miniArrStack{
private:
enum {DEF_CAPACITY =100}; //default stack capacity
DataType* arr; // The array of items
int capacity; // The size of the current array
int topIndex; // The location of the top element
public:
miniArrStack (); // Constructor for ArrStack
miniArrStack(const miniArrStack &l); // Copy contstructor
~miniArrStack(); // Destructor
int size() const; // get the number of elements in the stack
bool isEmpty() const; // Check if the stack is empty
const DataType& getElement(int);
const DataType& top() const; //get the top element without popping it
void push(const DataType &e); // Pushes an object onto the stack
void pop(); // Pop an object off the stack
void printStack() const; // Prints the stack from the top, down 3
miniListStack<DataType>& operator=(const miniArrStack<DataType>&); // Assignment operator
};

template <class DataType>
miniListStack<DataType>::miniListStack(){

} // Constructor for ListStack

template <class DataType>
miniListStack<DataType>::miniListStack(const miniListStack &l){
list = l.getList();
} // Copy contstructor

template <class DataType>
miniListStack<DataType>::~miniListStack(){} // Destructor

template <class DataType>
miniDList<DataType> miniListStack<DataType>::getList(){
    return list;
}

template <class DataType>
int miniListStack<DataType>::size() const{
return getList().size();
} // get the number of elements in the stack

template <class DataType>
bool miniListStack<DataType>::isEmpty() const{
if(list.size() == 0){
    return true;
}
return false;
} // Check if the stack is empty

template <class DataType>
const DataType& miniListStack<DataType>::top() const{
return list.back();
} //get the top emement without popping it

template <class DataType>
void miniListStack<DataType>::push(const DataType &e){
list.addFront(e);
} // Pushes an object onto the stack

template <class DataType>
void miniListStack<DataType>::pop(){
if(isEmpty() == false){
list.removeBack();
}
} // Pop an object off the stack

template <class DataType>
void miniListStack<DataType>::printStack() const{
list.display();
} // Prints the stack from the top, down 3

template <class DataType>
miniListStack<DataType>& miniListStack<DataType>::operator=(const miniListStack<DataType> &l){
list = l.getList();
} // Assignment operator


//************************************************************************//


template <class DataType>
miniArrStack<DataType>::miniArrStack (){
arr = new DataType[5];
topIndex = 0;
capacity = 5;
} // Constructor for ArrStack


template <class DataType>
miniArrStack<DataType>::miniArrStack(const miniArrStack &l){
arr = new DataType[l.size()];
capacity = l.size()+1;
for(int i = 0; i < l.size(); i++){
arr[i] = l.getElement(i);
}
} // Copy contstructor

template <class DataType>
miniArrStack<DataType>::~miniArrStack(){
    delete[] arr;
} // Destructor

template <class DataType>
int miniArrStack<DataType>::size() const{
return capacity-1;
} // get the number of elements in the stack

template <class DataType>
bool miniArrStack<DataType>::isEmpty() const{
if(capacity-1 == 0){
    return true;
}
return false;
} // Check if the stack is empty

template <class DataType>
const DataType& miniArrStack<DataType>::top() const{
return arr[topIndex];
} //get the top element without popping it

template <class DataType>
void miniArrStack<DataType>::push(const DataType &e){
arr[topIndex] = e;
topIndex++;
} // Pushes an object onto the stack

template <class DataType>
void miniArrStack<DataType>::pop(){
if(!isEmpty()){
arr[topIndex] = arr[topIndex+1];
capacity--;
}
} // Pop an object off the stack

template <class DataType>
void miniArrStack<DataType>::printStack() const{
for(int i = size(); i >= 0; i--){
    cout << arr[i] << endl;
}
} // Prints the stack from the top, down 3

template <class DataType>
miniListStack<DataType>& miniArrStack<DataType>::operator=(const miniArrStack<DataType> &l){
delete[] arr;
arr = new DataType[l.size()];
capacity = l.size()+1;
for(int i = 0; i < l.size(); i++){
    arr[i] = l.getElement(i);
}
} // Assignment operator

template <class DataType>
const DataType& miniArrStack<DataType>::getElement(int i){
return arr[i];
}

#endif
