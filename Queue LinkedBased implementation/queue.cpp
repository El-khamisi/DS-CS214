//
// Created by Mohammed El-khamisi on 2020-05-11.
//

#include "queue.h"

void initqueue(Queue *pq)
{
    pq->rear=pq->front=NULL;
    pq->size=0;
}


void append(QueueEntry e, Queue *pq)
{
    Node *pn=(Node *) malloc(sizeof(Node));
    pn->entry=e;
    pn->next=NULL;
    if (!pq->rear)
        pq->front=pn;
    else
        pq->rear->next=pn;
    pq->rear=pn;
    pq->size++;

}


void serve(QueueEntry *e,Queue *pq)
{
    Node *pn=pq->front;
    *e=pq->front->entry;
    pq->front=pq->front->next;
    free(pn);
    if (!pq->front)
        pq->rear=NULL;
    pq->size--;

}


int queueempty(Queue *pq)
{
    return (!pq->front);
}


int queuefull(Queue *pq)
{
    return 0;
}


int queuesize(Queue *pq)
{
    return pq->size;
}


void clearqueue(Queue *pq)
{
    while (pq->front)
    {
        pq->rear=pq->front->next;
        free(pq->front);
        pq->front=pq->rear;
    }
    pq->size=0;
}


void traversqueu(Queue *pq,void (*pf)(QueueEntry))
{
   for(Node *pn=pq->front; pn; pn=pn->next)
       (*pf) (pn->entry);
}

