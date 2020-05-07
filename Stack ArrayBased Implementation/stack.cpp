//
// Created by Mohammed El-khamisi on 2020-05-01.
//

#include "stack.h"

//Pre: None
void initStack(Stack *ps)
{
    ps->top=0;
}

//Pre:stack exists and not full
void push(stackEntry e, Stack *ps)
{
    ps->entry[ps->top++]=e;
}

//Pre:stack exist and not Empty
void pop(stackEntry *ep, Stack *ps)
{
    *ep=ps->entry[--ps->top];
}

//Pre: stack exist and has been initialized
int stackFull(Stack *ps)
{
    return ps->top >= MAXSIZE;
}
//Pre: stack exist and has been initialized
int stackEmpty(Stack *ps)
{
    return ps->top <= 0;
}

//Pre: stack has been created and not Empty
void stackTop(stackEntry *ep,Stack *ps)
{
    *ep=ps->entry[ps->top-1];
}

//Pre: stack has been created
void stackClear(Stack *ps)
{
    ps->top=0;
}

//Pre: stack has been created
int stackSize(Stack *ps)
{
    return ps->top;
}

//Pre: stack has been created
void traverseStack(Stack *ps, void (*pf)(stackEntry))
{
    for (int i =ps->top; i>0 ;i--)
        (*pf)(ps->entry[i-1]);
}