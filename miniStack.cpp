#include "miniStack.h"
#include <iostream>
using namespace std;

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
const DataType& miniListStack<DataType>::top() const throw(StackEmpty){
return list.back();
} //get the top emement without popping it

template <class DataType>
void miniListStack<DataType>::push(const DataType &e) throw(StackFull){
list.addFront(e);
} // Pushes an object onto the stack

template <class DataType>
void miniListStack<DataType>::pop() throw(StackEmpty){
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
miniArrStack<DataType>::miniArrStack (int cap= DEF_CAPACITY){
arr = new DataType[cap];
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
const DataType& miniArrStack<DataType>::top() const throw(StackEmpty){
return arr[top];
} //get the top element without popping it

template <class DataType>
void miniArrStack<DataType>::push(const DataType &e) throw(StackFull){
arr[top+1] = e;
capacity++;
} // Pushes an object onto the stack

template <class DataType>
void miniArrStack<DataType>::pop() throw(StackEmpty){
if(!isEmpty()){
arr[top] = arr[top+1];
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
