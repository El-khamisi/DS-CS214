//
// Created by Mohammed El-khamisi on 2020-05-01.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H


#define MAXSIZE 100
#define stackEntry int
typedef struct stack
{
    int top;
    stackEntry  entry[MAXSIZE];
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


#endif //STACK_STACK_H
