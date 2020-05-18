//
// Created by Mohammed El-khamisi on 2020-05-17.
//

#include "list.h"


void initlist(List *pl){
    pl->size=0;
}


void Insert(int pos, listEntry e, List *pl){
    for (int i = pl->size-1; i >=pos ; i--)
        pl->entry[i+1]=pl->entry[i];
    pl->entry[pos]=e;
    pl->size++;
}



void Delete(int pos , listEntry *e, List *pl){
    *e=pl->entry[pos];
    for (int i = pos+1; i <pl->size ; ++i)
        pl->entry[i-1]=pl->entry[i];
    pl->size--;
}


int listSize(List *pl){
    return pl->size;
}


int listEmpty(List *pl){
    return !pl->size;
}


int listFull(List *pl){
    return pl->size==MAXLIST;
}


void clearlist(List *pl){
    pl->size=0;
}


void Traverslist(List *pl, void (*pf)(listEntry)){
    for (int i = 0; i < pl->size; ++i)
        (*pf)(pl->entry[i]);
}


void Replacelist(int pos , listEntry e, List *pl){
    pl->entry[pos]=e;
}


void Retrievelist(int pos, listEntry *e, List *pl){
    *e=pl->entry[pos];
}
