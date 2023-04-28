#include <math.h>
#include <stdio.h>
#include "header.h"
#define Ten 10


int getMaxNumber(int *arr, int count){
    int max = arr[0];
    for (int i = 0; i < count; ++i) {
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
int countDigits(int val){
    return (val==0)?1:log10(val)+1;
}
int getDigit(int val,int digit) {
    return (int)(val / pow(Ten, digit - 1)) % Ten;
}

void radixSorting(int *arr, int count){
    Queue **queueArr = (Queue **)malloc(sizeof(Queue*) * Ten);
    for (int i = 0; i < Ten; ++i) {
        queueArr[i] = initQueue();
        queueArr[i]->Head = newNode(i);
    }
    for (int i = 0; i < Ten; ++i) {
        printf("%d",queueArr[i]->Head->data);
    }

}
