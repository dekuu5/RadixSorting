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
    return (int)(val / pow(Ten, digit - 1)) % Ten;
}
