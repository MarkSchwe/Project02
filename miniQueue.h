#ifndef miniQueue_h
#define miniQueue_h
#include "miniDList.h"
#include <iostream>
using namespace std;
template <class DataType>
class miniListQueue {
 private:
miniDList<DataType> list;
public:
miniListQueue (); // Constructor
miniListQueue(const miniListQueue &); // Copy Constructor
~miniListQueue(); // Destructor
miniDList<DataType> getList();
int size() const; // get the number of elements in the queue
bool isEmpty() const; // Check if the queue is empty
void enqueue(const DataType& e); // Enqueue element at rear
void dequeue(); // dequeue element at front
const DataType& front() const; //return the front element but not remove
void printQueue() const; // Prints the queue from the front to the rear
miniListQueue<DataType>& operator=(const miniListQueue<DataType>&); // Assignment operator
};

template <class DataType>
class miniArrQueue {
 private:
DataType* arr; // The array of items
int capacity; // The size of the current array
int frontIndex; // The location of the front element
int rear; // The location of the rear element
public:
miniArrQueue (); // Constructor
miniArrQueue(const miniArrQueue &); // Copy Constructor
~miniArrQueue(); // Destructor
int size() const; // get the number of elements in the queue
bool isEmpty() const; // Check if the queue is empty
void enqueue(const DataType& e); // Enqueue element at rear
void dequeue(); // dequeue element at front
const DataType& front() const; //return the front element but not remove
const DataType& getElement(int i);
void printQueue() const; // Prints the queue from the front to the rear
miniArrQueue<DataType>& operator=(const miniArrQueue<DataType>&); // Assignment operator
};

template <class DataType>
miniListQueue<DataType>::miniListQueue (){} // Constructor

template <class DataType>
miniListQueue<DataType>::miniListQueue(const miniListQueue &l){
list = l.getList();
} // Copy Constructor

template <class DataType>
miniListQueue<DataType>::~miniListQueue(){} // Destructor

template <class DataType>
miniDList<DataType> miniListQueue<DataType>::getList(){
    return list;
}

template <class DataType>
int miniListQueue<DataType>::size() const{
    return list.size;
} // get the number of elements in the queue

template <class DataType>
bool miniListQueue<DataType>::isEmpty() const{
    if(size == 0){
        return true;
    }
    return false;
} // Check if the queue is empty

template <class DataType>
void miniListQueue<DataType>::enqueue(const DataType& e){
    list.addBack(e);
} // Enqueue element at rear

template <class DataType>
void miniListQueue<DataType>::dequeue(){
    list.removeFront();
} // dequeue element at front

template <class DataType>
const DataType& miniListQueue<DataType>::front() const{
    return list.front();
} //return the front element but not remove

template <class DataType>
void miniListQueue<DataType>::printQueue() const{
    list.display();
} // Prints the queue from the front to the rear

template <class DataType>
miniListQueue<DataType>& miniListQueue<DataType>::operator=(const miniListQueue<DataType> &l){
list = l.getList();
} // Assignment operator




//************************************************************************//



template <class DataType>
miniArrQueue<DataType>::miniArrQueue (){
    frontIndex = 0;
    rear = 0;
    capacity = 1;
arr = new DataType[capacity];
} // Constructor

template <class DataType>
miniArrQueue<DataType>::miniArrQueue(const miniArrQueue &l){
arr = new DataType[l.size()];
capacity = l.size()+1;
for(int i = 0; i < l.size(); i++){
    arr[i] = l.getElement(i);
}
} // Copy Constructor

template <class DataType>
miniArrQueue<DataType>::~miniArrQueue(){
delete[] arr;
} // Destructor

template <class DataType>
int miniArrQueue<DataType>::size() const{
return capacity;
} // get the number of elements in the queue

template <class DataType>
bool miniArrQueue<DataType>::isEmpty() const{
if(size() == 0){
    return true;
}
return false;
} // Check if the queue is empty

template <class DataType>
void miniArrQueue<DataType>::enqueue(const DataType& e){
arr[rear] = e;
rear++;
capacity++;
if(rear>capacity){
    arr = new DataType[capacity];
}
} // Enqueue element at rear

template <class DataType>
void miniArrQueue<DataType>::dequeue(){
for(int i = 0; i < size()-1; i++){
    arr[i] = arr[i+1];
}
capacity--;
} // dequeue element at front

template <class DataType>
const DataType& miniArrQueue<DataType>::front() const{
return arr[frontIndex];
} //return the front element but not remove

template <class DataType>
void miniArrQueue<DataType>::printQueue() const{
for(int i = 0; i < size()-1; i++){
    cout << arr[i] << endl;
}
} // Prints the queue from the front to the rear

template <class DataType>
miniArrQueue<DataType>& miniArrQueue<DataType>::operator=(const miniArrQueue<DataType> &l){
delete[] arr;
arr = new DataType[l.size()];
capacity = l.size()+1;
for(int i = 0; i < l.size(); i++){
    arr[i] = l.getElement(i);
}
} // Assignment operator

template <class DataType>
const DataType& miniArrQueue<DataType>::getElement(int i){
return arr[i];
}

#endif
