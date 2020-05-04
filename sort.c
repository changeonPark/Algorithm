#include <stdio.h>
#include <limits.h> //int���� �ִ��� ����ϱ� ����.

#define SIZE 1000

int array[SIZE];

int swap(int *position, int *min){//���� �迭�� ���� ���� ���� ���� �迭�� ���� �ٲپ� �ֱ� ����.
    printf("Test code nonswap : %d %d %d %d\n", min, position, *min, *position);
    int temp; //�ٲٷ��� ���� �ӽ� �����ϱ� ���� ����.
    temp = *min;
    *min = *position;
    *position = temp;
    printf("Test code swap : %d %d %d %d\n", min, position, *min, *position);
}
void selectionSort(); //���� ���� �Լ� ����
void insertionSort(); //���� ���� �Լ� ����

void main(){
 //   selectionSort();
    insertionSort();
}

void selectionSort(){
    int num, idx, min;
    printf("�Է��� ���� ���� : ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++) scanf("%d", &array[i]); //�Է¹��� �� ��ŭ �迭�� ���� �Է� ����.

    for(int i = 0; i < num; i++){
        min = INT_MAX;//ó�� ���ۿ� ���� ���� �ʱ�ȭ�� ���� int�� �ִ��� �־��ش�.
        for(int j = i; j < num; j++){ //array[i - 1]�� ���� �ּڰ��� �����Ͽ����Ƿ� i��°�� ��ġ���� ���ϸ� �ȴ�...
            if(min > array[j]){
                min = array[j];
                idx = j;
            }
        }
        printf("test code: %d %d %d\n", array[i], &array[i], array[i]);
        swap(&array[i], &array[idx]);
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }
}

void insertionSort(){
    int num;
    printf("�Է��� ���� ���� : ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++) scanf("%d", &array[i]); //�Է¹��� �� ��ŭ �迭�� ���� �Է� ����.
    
    for(int i = 0; i < num - 1; i++){//a[j]�� a[j + 1]�� ���� ���ϹǷ� ������ �� ��.
    /*
        ex)3���� ���� �Է� �޾��� ��
        i�� 2�� �� ���� �ݺ��̹Ƿ� array[2]���� �񱳸� �ϰ� �ȴ� -> array[3]�� �����Ƿ�
        num - 1 = 2�� ������ ���ؼ� array[1]�� array[2]�� ���ϴ� ���� ���������� �ǰԲ� �ϱ� ����
        num -1���� �ݺ��� �Ѵ�.
    */
        int j = i; //while�� Ż�� ���� i���� �����ϹǷ� ���� j�� ���� i�� ������ ���߾��ش�.
        while (j >= 0 && array[j] > array[j+1])
        {
            swap(&array[j], &array[j+1]);
            j--;
        }
    }
    
    for(int i = 0; i < num; i++){
        printf("%d ", array[i]);
    }
}