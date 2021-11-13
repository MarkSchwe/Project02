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
const DataType& top() const throw(StackEmpty); //get the top emement without popping it
void push(const DataType &e) throw(StackFull); // Pushes an object onto the stack
void pop() throw(StackEmpty); // Pop an object off the stack
void printStack() const; // Prints the stack from the top, down 3
miniListStack<DataType>& operator=(const miniListStack<DataType> &l); // Assignment operator
};

template <class DataType>
class miniArrStack{
private:
enum {DEF_CAPACITY =100}; //default stack capacity
DataType* arr; // The array of items
int capacity; // The size of the current array
int top; // The location of the top element
public:
miniArrStack (int cap= DEF_CAPACITY); // Constructor for ArrStack
miniArrStack(const miniArrStack &l); // Copy contstructor
~miniArrStack(); // Destructor
int size() const; // get the number of elements in the stack
bool isEmpty() const; // Check if the stack is empty
const DataType& getElement(int);
const DataType& top() const throw(StackEmpty); //get the top element without popping it
void push(const DataType &e) throw(StackFull); // Pushes an object onto the stack
void pop() throw(StackEmpty); // Pop an object off the stack
void printStack() const; // Prints the stack from the top, down 3
miniListStack<DataType>& operator=(const miniArrStack<DataType>&); // Assignment operator
};

#include "miniStack.cpp"

#endif
