#include "header.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct node node;
struct node
{
    int data;
    node *next;
};
node *newNode(int data){
    node *n= (node *)malloc(sizeof(node));
    n->data=data;
    n->next=NULL;
    return n;
}
node *getNext(node *n){
    return n?n->next:n;
}

node *insNodeAfter(node *n,int value ){
    node *newN=newNode(value);
    if (n) { newN->next=getNext(n); n->next=newN;}
    return newN;
}

node *delNodeAfter(node *n) {  //O(1)
    if (n) { node *nextTo_n=getNext(n);
        if (nextTo_n)  {n->next=getNext(nextTo_n);free(nextTo_n);}
        //else n->next=NULL;
    }
    return n;
}
node *getTail(node *n) {
    if (n)
        while (getNext(n)) n=getNext(n);
    return n;
}
typedef struct {
    node *Head;
    node *Tail;
} Deque;

Deque *newDeque() {
    Deque *dq= (Deque *)malloc(sizeof(Deque));
    dq->Head=dq->Tail=NULL;
    return dq;
}
node * getHeadDQ(Deque *dq) {
    return dq->Head;
}
node * getTailDQ(Deque *dq) {
    return dq->Tail;
}


void insHead(Deque* dq,int val)        ///O(1)
{
    node *Head=getHeadDQ(dq);
    // node *n=insNodeAfter(NULL,val); // OR
    node *n=newNode(val);
    n->next=Head;dq->Head=n;
    if(!getTailDQ(dq)) dq->Tail=n;
}

void insTail(Deque* dq,int val)          ///O(1)
{
    node *Tail=getTailDQ(dq);
    node *nTail=dq->Tail=insNodeAfter(Tail,val);
    if(!getHeadDQ(dq)) dq->Head=nTail;
}


int isemptyDQ(Deque *dq){  /// O(1)
    return !getHeadDQ(dq);
}
void delHead(Deque *dq)                   ///O(1)
{
    node *Head=getHeadDQ(dq);
    if(!Head) {printf("Underflow"); return;}
    if(!getNext(Head)) /// Last element dead
        dq->Head = dq->Tail=NULL;
    else
        dq->Head = getNext(Head);
    free(Head);
}

typedef struct {Deque *dq;}Queue;
Queue* initQueue(){
    Queue* d=malloc(sizeof(Deque));
    d->dq=newDeque();return d;
}

void enQueue(Queue *q,int val){
    insTail(q->dq,val);
}
void dequeue(Queue*q){delHead(q->dq);}
int getFront(Queue*q){return getHeadDQ(q->dq)->data;}
int isQempty(Queue *q) {return  isemptyDQ(q->dq);;}

