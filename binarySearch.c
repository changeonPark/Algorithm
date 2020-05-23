#include <stdio.h>
#include <stdlib.h>
//2�� Ž��

int search(int start, int end, int target, int arr[]){
    if(start > end) return -99;
    
    int mid = (start + end) / 2;
    
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) return search(start, mid - 1, target, arr);
    else return search(mid + 1, end, target, arr);
}

void main(){
    int n, target;
    
    scanf("%d %d", &n, &target);
    int *arr;
    arr = malloc(sizeof(int*) * n);//n�� ��ŭ int�� ũ���� �迭 ����

    for(int i = 0; i < n; i++) { //i��° �迭�� �� ����.
        scanf("%d", &arr[i]);
    }
    
    int result = search(0, n - 1, target, arr);
    
    if(result != -99) printf("%d element\n", result + 1);
    else printf("not found\n");
}