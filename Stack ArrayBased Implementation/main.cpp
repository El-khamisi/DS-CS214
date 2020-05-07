#include <iostream>
#include "stack.h"
#include "stack.cpp"


using namespace std;


void print(stackEntry p)
{
    cout<< p<<"\t";
}
int main() {

    stackEntry e;
    Stack s;
    initStack(&s);

    if(!stackFull(&s))
    {
        push(11, &s);
        push(12, &s);
        push(13, &s);
    }

    traverseStack(&s, print);
    if(!stackEmpty(&s))
        pop(&e, &s);
    cout<<"the elemnt is "<<e<<endl;
    cout<< "travers is "; traverseStack(&s, print);cout<<endl;
    int x= stackSize(&s);
    cout<<"size is "<<x<<endl;
    if (!stackEmpty(&s))
        stackTop(&e, &s);
    cout<< "after top e is"<< e<<endl;
    cout<< "travers is "; traverseStack(&s, print);cout<<endl;
    x= stackSize(&s);
    cout<<"size is "<<x<<endl;



    stackClear(&s);
    cout<< "travers is "; traverseStack(&s, print);cout<<endl;
    x= stackSize(&s);
    cout<<"size is "<<x<<endl;



    cout << "Hello, World!" << endl;
    return 0;
}
