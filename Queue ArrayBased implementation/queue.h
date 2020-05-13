//
// Created by Mohammed El-khamisi on 2020-05-11.
//

#ifndef QUEUE_ARRAY_BASED_QUEUE_H
#define QUEUE_ARRAY_BASED_QUEUE_H


#define QueueEntry int
#define MAX_SIZE 100
#include <iostream>

typedef struct queue
{
    QueueEntry entry[MAX_SIZE];
    int front;
    int rear;
    int size;

}Queue;

void initqueue(Queue *);
void append(QueueEntry , Queue *);
void serve(QueueEntry *,Queue *);
int queueempty(Queue *);
int queuefull(Queue *);
int queuesize(Queue *);
void clearqueue(Queue *);
void traversqueu(Queue *,void (*)(QueueEntry));


#endif //QUEUE_ARRAY_BASED_QUEUE_H
