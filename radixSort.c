#include <stdio.h>
#include <stdlib.h>

void radixSort(int arr[], int len){
    int *result = malloc(len * sizeof(int));
    int exp = 1;
    int max = 0;
    for(int i = 0; i < len; i++){
            if(arr[i] > max) max = arr[i];
    }

    while(max / exp > 0){
        int bucket[10] = {0};
        for(int i = 0; i < len; i++) bucket[arr[i] / exp % 10]++;
        for(int i = 1; i < 10; i++) bucket[i] += bucket[i - 1];
        for(int i = len - 1; i > -1; i--) result[--bucket[arr[i] / exp % 10]] = arr[i];

        for(int i = 0; i < len; i++) arr[i] = result[i];

        exp *= 10;

    }
}


void main(){
    int arr[] = {3, 10, 5, 20, 257, 33, 47};
    int len = sizeof(arr) / sizeof(int);

    radixSort(arr, len);

    for(int i = 0; i < len; i++){
        printf(" %d", arr[i]);
    }
}