//
// Created by Mohammed El-khamisi on 2020-05-08.
//



#ifndef STACKLINKED_STACK_H
#define STACKLINKED_STACK_H

#include <iostream>
#include <stdlib.h>

#define stackEntry int


typedef struct stacknode
{
    stackEntry entry;
    struct stacknode *next;

}StackNode;

typedef struct stack
{
    StackNode *top;
}Stack;

void initStack(Stack *);
void push(stackEntry , Stack *);
void pop(stackEntry *, Stack *);
int stackFull(Stack *);
int stackEmpty(Stack *);
void stackTop(stackEntry *,Stack *);
void stackClear(Stack *);
int stackSize(Stack *);
void traverseStack(Stack *, void (*)(stackEntry));




#endif //STACKLINKED_STACK_H
