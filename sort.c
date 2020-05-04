#include <stdio.h>
#include <limits.h> //int형의 최댓값을 사용하기 위함.

#define SIZE 1000

int array[SIZE];

int swap(int *position, int *min){//현재 배열과 가장 작은 수를 가진 배열의 값을 바꾸어 주기 위함.
    printf("Test code nonswap : %d %d %d %d\n", min, position, *min, *position);
    int temp; //바꾸려는 값을 임시 저장하기 위한 변수.
    temp = *min;
    *min = *position;
    *position = temp;
    printf("Test code swap : %d %d %d %d\n", min, position, *min, *position);
}
void selectionSort(); //선택 정렬 함수 선언
void insertionSort(); //삽입 정렬 함수 선언

void main(){
 //   selectionSort();
    insertionSort();
}

void selectionSort(){
    int num, idx, min;
    printf("입력할 수의 갯수 : ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++) scanf("%d", &array[i]); //입력받은 수 만큼 배열에 숫자 입력 받음.

    for(int i = 0; i < num; i++){
        min = INT_MAX;//처음 시작에 비교할 수의 초기화를 위해 int형 최댓값을 넣어준다.
        for(int j = i; j < num; j++){ //array[i - 1]의 값은 최솟값을 대입하였으므로 i번째의 위치부터 비교하면 된다...
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
    printf("입력할 수의 갯수 : ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++) scanf("%d", &array[i]); //입력받은 수 만큼 배열에 숫자 입력 받음.
    
    for(int i = 0; i < num - 1; i++){//a[j]와 a[j + 1]의 값을 비교하므로 마지막 값 비교.
    /*
        ex)3개의 수를 입력 받았을 때
        i가 2일 때 까지 반복이므로 array[2]까지 비교를 하게 된다 -> array[3]은 없으므로
        num - 1 = 2의 전까지 비교해서 array[1]과 array[2]를 비교하는 것이 마지막으로 되게끔 하기 위해
        num -1까지 반복을 한다.
    */
        int j = i; //while문 탈출 이후 i값이 증가하므로 비교할 j의 값을 i의 값으로 맞추어준다.
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