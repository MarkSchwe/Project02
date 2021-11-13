#include "miniQueue.h"

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
void miniListQueue<DataType>::dequeue() throw(QueueEmpty){
    list.removeFront();
} // dequeue element at front

template <class DataType>
const DataType& miniListQueue<DataType>::front() const throw(QueueEmpty){
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
    front = 0;
    rear = 0;
    capacity = 1;
Arr = new DataType[capacity];
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
} // Enqueue element at rear

template <class DataType>
void miniArrQueue<DataType>::dequeue() throw(QueueEmpty){
delete[] arr[rear];
} // dequeue element at front

template <class DataType>
const DataType& miniArrQueue<DataType>::front() const throw(QueueEmpty){
return arr[front];
} //return the front element but not remove

template <class DataType>
void miniArrQueue<DataType>::printQueue() const{
for(int i = 0; i < size(); i++){
    cout << arr[i] << endl;
}
} // Prints the queue from the front to the rear

template <class DataType>
miniArrQueue<DataType>& miniArrQueue<DataType>::operator=(const miniArrQueue<DataType>&){
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
