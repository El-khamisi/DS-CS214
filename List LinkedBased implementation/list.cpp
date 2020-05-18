//
// Created by Mohammed El-khamisi on 2020-05-17.
//

#include "list.h"


void initlist(List *pl){
    pl->head=NULL;
    pl->size=0;
}


void Insert(int pos, listEntry e, List *pl){
    Node *temp,*pt=(Node *)malloc(sizeof(Node));
    pt->entry=e;
    int i=0;
    if (!pos)
    {
        pt->next=pl->head;
        pl->head=pt;
    }
    else
        {
        for (temp = pl->head, i = 0; i < pos - 1; i++)
            temp=temp->next;
        pt->next = temp->next;
        temp->next = pt;
    }
    pl->size++;
}



void Delete(int pos , listEntry *e, List *pl){
    Node *temp,*q;
    int i=0;
    if (!pos)
    {
        *e=pl->head->entry;
        temp=pl->head;
        pl->head=pl->head->next;
        free(temp);
//        temp=pl->head->next;
//        free(pl->head);
//        pl->head=temp;
    }
    else
    {
        for (q = pl->head, i = 0; i < pos - 1; i++)
            q=q->next;
        *e=q->next->entry;
        temp=q->next->next;
        free(q->next);
        q->next=temp;
    }
    pl->size--;
}


int listSize(List *pl){
    return pl->size;
}


int listEmpty(List *pl){
    return !pl->head;
}


int listFull(List *pl){
    return 0;
}


void clearlist(List *pl){
    Node *temp;
    while (pl->head)
    {
        temp=pl->head->next;
        free(pl->head);
        pl->head=temp;
    }
    pl->size=0;
}


void Traverslist(List *pl, void (*pf)(listEntry)){
    Node *p;
    for(p=pl->head; p; p=p->next)
        (*pf)(p->entry);
}


void Replacelist(int pos , listEntry e, List *pl){
    Node *temp;
    int i=0;
    for(temp=pl->head,i=0; i < pos ; i++)
        temp=temp->next;
    temp->entry=e;
}


void Retrievelist(int pos, listEntry *e, List *pl){
    Node *temp;
    int i=0;
    for(temp=pl->head,i=0; i < pos ; i++)
        temp=temp->next;
    *e=temp->entry;
}
