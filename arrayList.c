#include <stdio.h>
#define INF 10000
/*
배열 기반 리스트 -> 데이터를 순차적으로 저장 및 처리에 사용.
장점: 특정한 위치의 원소에 즉시 접근 가능
단점: 데이터가 들어갈 공간 미리 할당 필요
      원하는 위치에 삽입, 삭제 비효율적
*/
int arr[INF];
int cnt = 0;

void addBack(int data){
    arr[cnt] = data; //입력받은 수 배열에 삽입.
    printf("%d ", arr[cnt]); //확인용
    cnt++;
}

void addFirst(int data){
//맨 끝부터 맨 앞 직전까지 반복.
    for(int i = cnt; i>=1; i--){
        arr[i] = arr[i - 1]; //뒷자리로 한칸씩 밀어준다.
    }
    arr[0] = data; //0번째에 입력받은 데이터 삽입
    printf("%d ", arr[0]); //확인용
    cnt++;
}

void show(){
    for(int i = 0; i < cnt; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delIndex(){
    int num;
    int check = 0; // 입력받은 수가 배열의 크기보다 큰지 확인.
    printf("\n지우고 싶은 자리를 입력하세요: ");
    scanf("%d", &num);
    for(int i = (cnt -1); i >= 0; i--){//배열 맨끝부터 0번째까지 반복.
        if(num == i){ // 입력 받은 수가 배열안에 있을 경우
            for(int j = num; j < cnt - 1; j++){//
                arr[j] = arr[j + 1];
            }
            cnt --; //cnt는 총 입력된 배열보다 1 크고, 한칸씩 당겨졌으므로 1 빼줌.
            check = 0; //참
        }
        check = 1; //구라
    }
    if( check == 0){}
    else{
        printf("Not Index\n");
    }
}

void main(){
    addBack(10);
    addBack(9);
    addBack(8);
    addBack(7);
    delIndex();
    addFirst(6);
    addFirst(5);
    show();
}