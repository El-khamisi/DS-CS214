//
// Created by Mohammed El-khamisi on 2020-05-08.
//

#include "stack.h"

void initStack(Stack *sp)
{
    sp->top=NULL;
}

void push(stackEntry e, Stack *sp)
{
    StackNode *pn=(StackNode *)malloc(sizeof(StackNode));
    pn->entry=e;
    pn->next=sp->top;
    sp->top=pn;

}
void pop(stackEntry *e, Stack *sp)
{
    StackNode *p=sp->top;
    *e=sp->top->entry;
    sp->top=sp->top->next;
    free(p);

}
int stackFull(Stack *sp)
{
    return 0;
}
int stackEmpty(Stack *sp)
{
    return sp->top==NULL;
}
void stackTop(stackEntry *e,Stack *sp)
{
    *e=sp->top->entry;
}
void stackClear(Stack *sp)
{
   StackNode *p=sp->top;
   while (p)
   {
      p=p->next;
      free(sp->top);
      sp->top=p;
   }
}
int stackSize(Stack *sp)
{
    int x=0;
    for(StackNode *p=sp->top; p ; p=p->next)
        x++;
    return x;
}
void traverseStack(Stack *sp, void (*pf)(stackEntry))
{
    for(StackNode *p=sp->top; p ; p=p->next)
        (*pf) (p->entry);
}
