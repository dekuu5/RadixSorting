#include <math.h>
#include <stdio.h>
#include "header.h"
#define Ten 10
//getMax();
//CountDigits()

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
    return (int)(val / pow(Ten, digit)) % Ten;
}


void radix_sort(int *ar,int count){
    int max= getMaxNumber(ar,count);
    int digits=countDigits(max);
    int index,value;
    for(int i=0;i<digits;i++){
        node* queues_Array[10]={NULL};
        for(int j=0;j<count;j++){
            enqueue_array(queues_Array, getDigit(ar[j], i), ar[j]);
        }
        dequeue_to_array(ar,queues_Array);
    }
}