#include <stdio.h>

int arr[5] = {2, 1, 3, 5 ,4};

void swap(int *previous, int *next){
    int temp;
    temp = *previous;
    *previous = *next;
    *next = temp;   
}

void main(){
    /*for(int i = 1; i < 4;  i++){
        for(int j = i; j >= 0; j--){ --> �̹� �������� ���ĵ� ���� �迭�鵵 �� �ѹ��� if�� ��ġ�� ������ ��ȿ�����̴�. --> ������� �� ��.
            if(arr[j + 1] < arr[j]){
                printf("%d\n", j);
                printf("none: j+1 : %d j: %d\n", arr[j + 1], arr[j]);
                swap(&arr[j + 1], &arr[j]);
                printf("swap: %d %d\n", arr[j + 1], arr[j]);
            }
        }
        
    }*/

    for(int i = 0; i < 4;  i++){
        int j = i;
        while(j >= 0 && arr[j+1] < arr[j]){
            printf("%d\n", j);
            printf("none: j+1 : %d j: %d\n", arr[j + 1], arr[j]);
            swap(&arr[j + 1], &arr[j]);
            printf("swap: %d %d\n", arr[j + 1], arr[j]);
            j--;
        }
    }


    for(int i = 0; i < 5; i++){
        printf("%d\n", arr[i]);
    }

}
