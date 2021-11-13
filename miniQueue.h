#ifndef miniQueue_h
#define miniQueue_h
#include "miniDList.h"

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
void dequeue() throw(QueueEmpty); // dequeue element at front
const DataType& front() const throw(QueueEmpty); //return the front element but not remove
void printQueue() const; // Prints the queue from the front to the rear
miniListQueue<DataType>& operator=(const miniListQueue<DataType>&); // Assignment operator
};

template <class DataType>
class miniArrQueue {
 private:
DataType* arr; // The array of items
int capacity; // The size of the current array
int front; // The location of the front element
int rear; // The location of the rear element
public:
miniArrQueue (); // Constructor
miniArrQueue(const miniArrQueue &); // Copy Constructor
~miniArrQueue(); // Destructor
int size() const; // get the number of elements in the queue
bool isEmpty() const; // Check if the queue is empty
void enqueue(const DataType& e); // Enqueue element at rear
void dequeue() throw(QueueEmpty); // dequeue element at front
const DataType& front() const throw(QueueEmpty); //return the front element but not remove
const DataType& miniArrQueue::getElement(int i);
void printQueue() const; // Prints the queue from the front to the rear
miniArrQueue<DataType>& operator=(const miniArrQueue<DataType>&); // Assignment operator
};

#include "miniQueue.cpp"

#endif
