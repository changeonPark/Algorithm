#include <stdio.h>
#include <limits.h> //int���� �ִ��� ����ϱ� ����.

#define SIZE 1000

int array[SIZE];
int arr[6] = {1, 3, 2, 4, 9, 7};
int check;
int swap(int *x, int *y){//���� �迭�� ���� ���� ���� ���� �迭�� ���� �ٲپ� �ֱ� ����.
    int temp; //�ٲٷ��� ���� �ӽ� �����ϱ� ���� ����.
    temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(); //���� ���� �Լ� ����
void insertionSort(); //���� ���� �Լ� ����
void leftquickSort(int left, int right, int check);
void rightquickSort(int left, int right);
void funcquickSort(int left, int right);
int partition(int left, int right);
/*
���� ���İ����� ������ ����(�Ϸķ� ������ ī�� ��ġ�� ���� ���.)
���� ����: ���ʴ�� ī�带 �ϳ��� ����(1)�ϰ� ���ĵ� ī���� ���������� �񱳸� �Ͽ��� ��! ���� ���� ī�带 '����'(2)�Ͽ� 1�� 2�� ��ġ�� �ٲ��ش�.
���� ����: ���ʴ�� ī�带 �����Ͽ� �տ� ���ĵ� ī���� ���� �ڽ��� �ڸ��� �����Ѵ�.

*/



void main(){
    //selectionSort();
    //insertionSort();
    //rightquickSort(0, 5);
    funcquickSort(0, 5);
    for(int i = 0; i < 6; i++){
        printf("%d\n", arr[i]);
    }
}

/*
    ��ü �迭���� �ּڰ��� �迭�� ��ġ�� ã�Ƴ� �����Ͽ� �񱳸� ������ ��ġ�� �迭�� �¹ٲ۴�.
    �迭�� ��ġ�� �� ���� ������ �ִ�. 
    �� ���� �� �迭�� '��ġ'���� ���������� ���ϰ� ��ġ�� �´� ���� "����" �Ͽ� �����Ѵ�.
    �ּڰ��� min�� �����Ѵ�.(������ ���� �ּڰ��� �����ϱ� ����.)
    1. �迭�� ó������ ���������� �ݺ��Ѵ�.
        1 - 1. ������ ��ġ�������� ���������� �ݺ��Ѵ�.
            1 - 1 - 1. �� ��ġ�� �迭�� ���� �ּڰ����� ���� ��� �� �迭�� ���� min�� �����ϰ� ��ġ�� ����صд�.
        1 - 2. �ּڰ��� ��ϵ� ��ġ�� 1 - 1 ��ġ�� �迭�� ����  �ٲپ��ش�.
    
*/
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


/*
    ���ĵ� �迭���� �ڽ��� ��ġ�� �´� �迭�� ���� �����Ѵ�. ex)ī�� ����
*/
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

void leftquickSort(int left, int right, int check){
    if(left >= right) return;
    int pivot = left, i = left + 1, j = right, chk = check;
    printf("check: %d\n", chk);
    while(i <= j){//left�� right�� �������� ������ �ݺ�
        while(i <= right && arr[i] <= arr[pivot]){
            i++;
            printf("i = %d\n", i);
        }
        while(j > left && arr[j] >= arr[pivot]){
            j--;
            printf("j = %d\n", j);
        }
        if(i > j) swap(&arr[pivot], &arr[j]);
        else swap(&arr[i], &arr[j]);
    }
    leftquickSort(left, j - 1, 0);
    leftquickSort(j + 1, right, 1);
    
}

void rightquickSort(int left, int right){
    if(left < right){
        int pivot = right, i = left, j = right - 1;

        while(i <= j){
            while(i < right && arr[i] < arr[pivot]) i++; //pivot���� ū �� ���ʿ������� search
            while(j >= left && arr[j] > arr[pivot]) j--; //pivot���� ���� ���� �����ʿ������� search

            if(i <= j) swap(&arr[i], &arr[j]);
            else swap(&arr[pivot], &arr[i]);
        }

        rightquickSort(left, i - 1); //���� ó������ pivot ���� ������
        rightquickSort(i + 1, right); //pivot ���� ������ ������ ������
    }
}

int partition(int left, int right){
    int pivot = right;//pivot�� �ֿ��� ������ ����
    int cnt = left; //���ʺ��� ���� �� pivot�� ������ ���� ��츦 ����ϱ� ����.>> ù ���� pivot���� �۰� �� ��� ������.

    for(int i = left; i < right; i++){//���ʺ��� ������ - 1(pivot�� �� ���������� ���߱� ����)���� �ݺ�
        if(arr[i] < arr[pivot]){ //���� ��ġ�� ���� pivot�� ������ ���� ���
            
            swap(&arr[cnt], &arr[i]);//���� ���� cnt��ġ�� ���� �ٲ��ش�.
            cnt++; //cnt�� �������� �ش�.
        }
    }
    swap(&arr[cnt], &arr[pivot]);
    return cnt;
}

void funcquickSort(int left, int right){
    if(left < right){
        int point = partition(left, right);

        funcquickSort(left, point - 1);
        funcquickSort(point + 1, right);
    }
}

