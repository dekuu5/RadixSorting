#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char* getInput() {
    char* input = (char*)malloc(256 * sizeof(char));
    printf("Enter an array like this 2-3-5-6-7-8:\n");
    if (scanf("%255[-0-9]s", input) == 1) {
        printf("You entered: %s\n", input);
    } else {
        printf("Invalid input\n");
    }
    return input;
}



void getArrayFromString(int * arr,char* str, int* arrSize) {
    int size = 0;
    char* token;
    token = strtok(str, "-");
    int i = 0;
    while (token != NULL) {
        if (*token != '\0') {
            arr[i++] = atoi(token);
            size++;
        }
        token = strtok(NULL, "-");
    }
    *arrSize = size;
}