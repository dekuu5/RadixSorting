#include "header.h"
#include <stdio.h>


int main(){
    int ar[]={183,33,93,3,92};
    radix_sort(ar,5);
    for(int i=0;i<5;i++){
        printf("%d  ",ar[i]);
    }
    printf("\n");
    return 0;
}