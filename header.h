//
// Created by pc on 4/28/2023.
//

#ifndef RADIXSORTING_HEADER_H
#define RADIXSORTING_HEADER_H
typedef struct node node;

node *newNode(int data);
node *getNext(node *n);
node *insNodeAfter(node *n,int value );
node *delNodeAfter(node *n);
node *getTail(node *n);
typedef struct {

}Queue;
Queue* initQueue();
node * getHeadQ(Queue *q);
node * getTailQ(Queue *q);
void enQueue(Queue *q,int val);
int dequeue(Queue *q);int getFront(Queue*q);
int isQempty(Queue *q);

//radix.cpp
int getMaxNumber(int *arr, int count);
int countDigits(int val);
int getDigit(int val,int digit);

void enqueue_array(node **ar,int index,int value);
void dequeue_to_array(int *ar,node **queues);
void radix_sort(int *ar,int count);
#endif //RADIXSORTING_HEADER_H
