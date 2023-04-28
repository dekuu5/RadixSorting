//
// Created by pc on 4/28/2023.
//

#ifndef RADIXSORTING_HEADER_H
#define RADIXSORTING_HEADER_H

// queue.cpp
typedef struct node node;

node *newNode(int data);
node *getNext(node *n);
node *insNodeAfter(node *n,int value );
node *delNodeAfter(node *n);
node *getTail(node *n);
typedef struct Queue Queue;
//typedef struct Queue {} Queue;
Queue* initQueue();
node * getHeadQ(Queue *q);
node * getTailQ(Queue *q);
void enQueue(Queue *q,int val);
int dequeue(Queue *q);int getFront(Queue*q);
int isQempty(Queue *q);


// radix.cpp

int getDigit(int val,int digit);
int getMaxNumber(int *arr, int count);
int countDigits(int val);
void radixSorting(int *arr, int count);

#endif //RADIXSORTING_HEADER_H
