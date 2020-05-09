#include <stdio.h>
#include <limits.h> //int형의 최댓값을 사용하기 위함.

#define SIZE 1000

int array[SIZE];
int arr[6] = {1, 3, 2, 4, 9, 7};
int check;
int swap(int *x, int *y){//현재 배열과 가장 작은 수를 가진 배열의 값을 바꾸어 주기 위함.
    int temp; //바꾸려는 값을 임시 저장하기 위한 변수.
    temp = *x;
    *x = *y;
    *y = temp;
}
void selectionSort(); //선택 정렬 함수 선언
void insertionSort(); //삽입 정렬 함수 선언
void leftquickSort(int left, int right, int check);
void rightquickSort(int left, int right);
void funcquickSort(int left, int right);
int partition(int left, int right);
/*
선택 정렬과삽입 정렬의 차이(일렬로 펼쳐진 카드 뭉치를 예로 든다.)
선택 정렬: 차례대로 카드를 하나씩 선택(1)하고 정렬된 카드의 마지막까지 비교를 하였을 때! 가장 작은 카드를 '선택'(2)하여 1과 2의 위치를 바꿔준다.
삽입 정렬: 차례대로 카드를 선택하여 앞에 정렬된 카드들과 비교해 자신의 자리에 삽입한다.

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
    전체 배열에서 최솟값의 배열의 위치를 찾아내 선택하여 비교를 시작한 위치의 배열과 맞바꾼다.
    배열의 위치에 들어갈 값은 정해져 있다. 
    들어갈 값을 각 배열을 '위치'에서 마지막까지 비교하고 위치에 맞는 값을 "선택" 하여 정렬한다.
    최솟값을 min에 저장한다.(최초의 값을 최솟값에 저장하기 위함.)
    1. 배열을 처음부터 마지막까지 반복한다.
        1 - 1. 증가된 위치에서부터 마지막까지 반복한다.
            1 - 1 - 1. 현 위치의 배열의 값이 최솟값보다 작을 경우 현 배열의 값을 min에 저장하고 위치를 기록해둔다.
        1 - 2. 최솟값이 기록된 위치를 1 - 1 위치의 배열과 값을  바꾸어준다.
    
*/
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


/*
    정렬된 배열에서 자신의 위치에 맞는 배열의 값을 삽입한다. ex)카드 정리
*/
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

void leftquickSort(int left, int right, int check){
    if(left >= right) return;
    int pivot = left, i = left + 1, j = right, chk = check;
    printf("check: %d\n", chk);
    while(i <= j){//left와 right가 엇갈리기 전까지 반복
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
            while(i < right && arr[i] < arr[pivot]) i++; //pivot보다 큰 수 왼쪽에서부터 search
            while(j >= left && arr[j] > arr[pivot]) j--; //pivot보다 작은 수를 오른쪽에서부터 search

            if(i <= j) swap(&arr[i], &arr[j]);
            else swap(&arr[pivot], &arr[i]);
        }

        rightquickSort(left, i - 1); //왼쪽 처음부터 pivot 이전 값까지
        rightquickSort(i + 1, right); //pivot 다음 값에서 오른쪽 끝까지
    }
}

int partition(int left, int right){
    int pivot = right;//pivot을 최우측 값으로 결정
    int cnt = left; //왼쪽부터 비교할 때 pivot의 값보다 작은 경우를 기록하기 위함.>> 첫 값이 pivot보다 작게 될 경우 오류남.

    for(int i = left; i < right; i++){//왼쪽부터 오른쪽 - 1(pivot을 맨 우측값으로 정했기 때문)까지 반복
        if(arr[i] < arr[pivot]){ //현재 위치의 값이 pivot의 값보다 작을 경우
            
            swap(&arr[cnt], &arr[i]);//현재 값을 cnt위치의 값과 바꿔준다.
            cnt++; //cnt를 증가시켜 준다.
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

