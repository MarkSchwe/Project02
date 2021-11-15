#ifndef miniDList_h
#define miniDList_h
#include <iostream>
using namespace std;
template <class DataType>
class miniDList{
private:
struct DNode{ // doubly linked list node
DataType data; // data stored in node 
DNode* next; // next node in list 
DNode* prev; // previous node in list
};
DNode* header; // list sentinels
DNode* trailer;
public:
miniDList(){ // constructor
header = new DNode;
trailer = new DNode; //have them point to each other
header->next = trailer;
trailer->prev = header;
}
miniDList(const miniDList& l); // Copy constructor
~miniDList(); // Destructor
const DataType& front() const; // get front element
const DataType& back() const; // get back element
void removeFront(); // Remove & return the front
void removeBack(); // Remove & return the back 
void addFront(const DataType& e); // Add to the front
void addBack(const DataType& e); // Add to the back
int size() const; // Returns the number of elements in list
bool contains(const DataType& e); // Tests for membership
void display() const; // Prints the elements of list
miniDList<DataType>& operator=(const miniDList<DataType>& l); 
//Overloaded assignment
protected: //local utilities
void add(DNode * v, const DataType& e); //insert new node before v
void remove(DNode* v); //remove node v
};

template <class DataType>
miniDList<DataType>::miniDList(const miniDList& l){
DNode *copy = l->header->next;
while(copy != l->trailer){
addFront(copy->data);
}
} // Copy constructor

template <class DataType>
miniDList<DataType>::~miniDList(){
DNode *test = header;
while(test->next != trailer){
    removeBack();
}
test = nullptr;
} // Destructor

template <class DataType>
const DataType& miniDList<DataType>::front() const{
    return header->next->data;
} // get front element

template <class DataType>
const DataType& miniDList<DataType>::back() const{
    return trailer->prev->data;
} // get back element

template <class DataType>
void miniDList<DataType>::removeFront(){
DNode *delNode = header->next;
DNode *link = delNode->next;
header->next = link;
link->prev = header;
delete delNode;
} // Remove & return the front

template <class DataType>
void miniDList<DataType>::removeBack(){
DNode *delNode = trailer->prev;
DNode *link = delNode->prev;
link->next = trailer;
trailer->prev = link;
delete delNode;
} // Remove & return the back 

template <class DataType>
void miniDList<DataType>::addFront(const DataType& e){
DNode *insert = new DNode;
insert->data = e;
DNode *after = header->next;
after->prev = insert;
insert->next = after;
insert->prev = header;
header->next = insert;
} // Add to the front

template <class DataType>
void miniDList<DataType>::addBack(const DataType& e){
DNode *insert = new DNode;
insert->data = e;
DNode *before = trailer->prev;
before->next = insert;
trailer->prev = insert;
insert->next = trailer;
insert->prev = before;
} // Add to the back

template <class DataType>
int miniDList<DataType>::size() const{
DNode *Test = header;
int listSize = 0;
Test = Test->next;
while (Test != trailer){
    listSize++;
    Test = Test->next;
}
Test = nullptr;
return listSize;
} // Returns the number of elements in list

template <class DataType>
bool miniDList<DataType>::contains(const DataType& e){
DNode *Test = header;
while (Test != trailer && Test->data != e){
    Test = Test->next;
}
if(Test->data == e){
    return true;
} else {
    return false;
}
Test = nullptr;
} // Tests for membership

template <class DataType>
void miniDList<DataType>::display() const{
DNode *Test = header->next;
while (Test != trailer){
    cout << "Data: " << Test->data << endl;
    Test = Test->next;
}
Test = nullptr;
} // Prints the elements of list

template <class DataType>
miniDList<DataType>& miniDList<DataType>::operator=(const miniDList<DataType>& l){
while(header->next != trailer){
removeFront(header->next);
}
DNode *copy = l->header->next;
while(copy != l->trailer){
addFront(copy->data);
}
} //Overloaded assignment

template <class DataType>
void miniDList<DataType>::add(DNode * v, const DataType& e){
DNode *insert = new DNode;
insert->data = e;
DNode *search = header;
while(search->next != v && search->next != trailer){
    search = search->next;
}
if(search->next == v){
    insert->next = v;
    insert->prev = search;
    search->next = insert;
    v->prev = insert;
} else {
    cout << "insert location not found." << endl;
}
} //insert new node before v

template<class DataType>
void miniDList<DataType>::remove(DNode* v){
DNode *delNode = header;
DNode *after, *before;
while(delNode != v && delNode != trailer){
delNode = delNode->next;
} 
if(delNode == v){
after = delNode->next;
before = delNode->prev;
after->prev = before;
before->next = after;
delete delNode;
} else {
    cout << "node for deletion not found." << endl;
}
} //remove node v

#endif
