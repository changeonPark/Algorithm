#include <stdio.h>
#define NUMBER 7

int g_tree[NUMBER];
//1~N까지의 구간합을 구하는 함수
int Sum(int index){
    int result = 0;
    while(index > 0){
        result += g_tree[index];
        //마지막 비트만큼 현재 값에서 빼줌.
        index -= (index & -index);
    }
    return result;
}
//특정 인덱스 수정
void Updata(int index, int dif){
    while(index <= NUMBER){
        g_tree[index] += dif;
        //마지막 비트만큼 더해준다.
        index += (index & -index);
    }
}
//구간 합 계산 함수
int GetSection(int start, int end){
    return Sum(end) - Sum(start - 1);
}

void main(){
    Updata(1, 7);
    Updata(2, 1);
    Updata(3, 9);
    Updata(4, 5);
    Updata(5, 6);
    Updata(6, 4);
    Updata(7, 1);
    printf("1~7까지의 구간합 : %d\n", GetSection(1, 7));
    printf("인덱스 6의 원소를 2만큼 수정\n");
    Updata(6, 2);
    printf("1~7까지의 구간합 : %d\n", GetSection(1, 7));
    printf("2~5까지의 구간합 : %d\n", GetSection(2, 5));
}


