#include <stdio.h>
#define MAX 1001

void main(){
    int n, m, a[MAX] = {0}, result[5], cnt = 0;
    printf(":::: ");
    for(int i = 0; i < 5; i++){
        scanf("%d", &m);
        a[m]++; //a배열 m번째 위치의 값 1씩 증가
    }

    for(int i = 0; i < MAX; i++){
        while(a[i] != 0){ //a배열의 i번째 위치의 값이 0이 아닐 때 까지
            result[cnt] = i;
            cnt++;
            a[i]--;
            
            //printf("%d ", i);//i의 값을 출력
            //a[i]--;//a배열의 i번째 위치의 값 1씩 감소
        }
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", result[i]);
    }
}

