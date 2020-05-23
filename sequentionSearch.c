#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** arr;
int founded;
//순차 탐색
void main(){
    int n;
    char *word;
    word = malloc(sizeof(char) * 100); //100칸 입력가능한 문자열 배열
    scanf("%d %s", &n, word);
    arr = (char**)malloc(sizeof(char*) * n); //n개 만큼 char크기의 배열 행 생성

    for(int i = 0; i < n; i++){
        arr[i] = malloc(sizeof(char) * 100); //char크기의 문자가 100개 들어갈 만큼의 배열 열을 arr[i]에 생성
        scanf("%s", arr[i]);
    }

    for(int i = 0; i < n; i++){
        if(!strcmp(arr[i], word)){
            printf("%d번째 원소\n %d\n", i + 1, strcmp(arr[i], word));
            founded = 1;
        }
    }

    if(!founded) printf("not found\n");

}