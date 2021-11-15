#include "miniStack.h"
#include "miniQueue.h"
#include "miniDList.h"
#include <iostream>
using namespace std;


int main(){
//miniDList<int>test;
//miniListStack<int> test2;
//miniArrStack<int> test3;
miniArrQueue<int> test4;
//miniListQueue<int> test5;
/*
for(int i = 0; i < 5; i++){
    test.addFront(i);
}
test.display();
test.removeBack();
test.removeFront();
test.display();
cout << test.size() << endl;
cout << test.contains(10) << endl;
cout << test.back() << endl;
cout << test.front() << endl;
*/


/*
for(int i = 0; i < 5; i++){
    test2.push(i);
}
test2.printStack();
test2.pop();
test2.printStack();
*/

/*
for(int i = 0; i < 5; i++){
    test3.push(i);
}
test3.printStack();
test3.pop();
test3.printStack();
*/

for(int i = 0; i < 5; i++){
    test4.enqueue(i);
}
test4.printQueue();
test4.dequeue();
test4.printQueue();

/*
for(int i = 0; i < 5; i++){
    test5.enqueue(i);
}
test5.printQueue();
test5.dequeue();
test5.printQueue();
*/
return 0;
}
