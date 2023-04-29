#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    while (1){
        doRadix();
        printf("do you want to Enter an other array(y,n):");
        char ans;
        scanf(" %c",&ans);
        if (ans == 'y'){
            continue;
        } else if(ans == 'n') exit(0);
        else {
            printf("didn't receive a valid answer exiting.....");
            exit(-1);
        }
    }
    return 0;
}

