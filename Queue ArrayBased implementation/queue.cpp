//
// Created by Mohammed El-khamisi on 2020-05-11.
//

#include "queue.h"

void initqueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}


void append(QueueEntry e, Queue *pq)
{
   pq->rear=(pq->rear+1) % MAX_SIZE;
   pq->entry[pq->rear]=e;
   pq->size++;

}


void serve(QueueEntry *e,Queue *pq)
{
    *e=pq->entry[pq->front];
    pq->front=(pq->front+1) % MAX_SIZE;
    pq->size--;


}


int queueempty(Queue *pq)
{
    return !pq->size;
}


int queuefull(Queue *pq)
{
    return (pq->size == MAX_SIZE);
}


int queuesize(Queue *pq)
{
    return pq->size;
}


void clearqueue(Queue *pq)
{
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}



void traversqueu(Queue *pq,void (*pf)(QueueEntry))
{

    for(int pos=pq->front,s=0; s<pq->size; s++)
    {
        (*pf) (pq->entry[pos]);
        pos=(pos+1) % MAX_SIZE;
    }


}

