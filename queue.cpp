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
/*typedef struct {
    node *Head;
    node *Tail;
}Queue;
Queue* initQueue(){
    Queue *q= (Queue *)malloc(sizeof(Queue));
    q->Head = NULL;
    q->Tail = NULL;
    return q;
}
node * getHeadQ(Queue *q) {
    return q->Head;
}
node * getTailQ(Queue *q) {
    return q->Tail;
}

void enQueue(Queue *q,int val){
    node *Tail=getTailQ(q);
    node *nTail = insNodeAfter(Tail,val);
    q->Tail= nTail;
}
int dequeue(Queue *q){
    node *Head=getHeadQ(q);
    int data = Head->data;
    if(!getNext(Head)) {
        q->Head = NULL;
        q->Tail = NULL;
    }else
        q->Head = getNext(Head);
    free(Head);
    return data;
}
int getFront(Queue*q){return getHeadQ(q)->data;}

int isQempty(Queue *q) {
    return !getHeadQ(q);
}

*/

void enqueue_array(node **ar,int index,int value){
    node *newN=newNode(value);
    if(ar[index]){
        node *tail=getTail(ar[index]);
        tail->next=newN;
    }
    else ar[index]=newN;
}

void dequeue_to_array(int *ar,node **queues){
    int j=0;
    node *del;
    int value;
    for(int i=0;i<10;i++){
        while (queues[i]){
            del=queues[i];
            queues[i]=queues[i]->next;
            value=del->data;
            free(del);
            ar[j++]=value;
        }
    }
}