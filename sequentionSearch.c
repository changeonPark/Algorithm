#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** arr;
int founded;
//���� Ž��
void main(){
    int n;
    char *word;
    word = malloc(sizeof(char) * 100); //100ĭ �Է°����� ���ڿ� �迭
    scanf("%d %s", &n, word);
    arr = (char**)malloc(sizeof(char*) * n); //n�� ��ŭ charũ���� �迭 �� ����

    for(int i = 0; i < n; i++){
        arr[i] = malloc(sizeof(char) * 100); //charũ���� ���ڰ� 100�� �� ��ŭ�� �迭 ���� arr[i]�� ����
        scanf("%s", arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(!strcmp(arr[i], word)){
            printf("%d��° ����\n %d\n", i + 1, strcmp(arr[i], word));
            founded = 1;
        }
    }

    if(!founded) printf("not found\n");

}