#include <stdio.h>
#define MAX 1001

void main(){
    int n, m, a[MAX] = {0}, result[5], cnt = 0;
    printf(":::: ");
    for(int i = 0; i < 5; i++){
        scanf("%d", &m);
        a[m]++; //a�迭 m��° ��ġ�� �� 1�� ����
    }

    for(int i = 0; i < MAX; i++){
        while(a[i] != 0){ //a�迭�� i��° ��ġ�� ���� 0�� �ƴ� �� ����
            result[cnt] = i;
            cnt++;
            a[i]--;
            
            //printf("%d ", i);//i�� ���� ���
            //a[i]--;//a�迭�� i��° ��ġ�� �� 1�� ����
        }
    }

    for(int i = 0; i < 5; i++){
        printf("%d ", result[i]);
    }
}

