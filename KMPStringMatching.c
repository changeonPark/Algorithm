#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* parent = "ABCDEFG";
char* pattern = "CG";

void SimpleMatching(){
    int parentsize = strlen(parent);
    int patternsize = strlen(pattern);
    int found;
    for(int i = 0; i < parentsize; i++){
        found = 1;
        for(int j = 0; j < patternsize; j++){
            if(parent[i + j] != pattern[j]){
                found = 0;
                break;
            }
        }
        if(found){
            printf("%d번째에서 찾음!\n", i + 1);
            break;
        }
    }
    if(!found){
        printf("찾을 수 없쪙!\n");
    }
}

char* kmpparent = "acabacdabac";
char* kmppattern = "cdabac";
//테이블 생성 함수
int* MakeTable(char* kmppattern){
    int patternsize = strlen(kmppattern);
    int* table = (int*)malloc(sizeof(int) * patternsize);//table의 길이 = 패턴의 길이 --> 메모리 할당
    //table 배열 0으로 초기화
    for(int i = 0; i < patternsize; i++){
        table[i] = 0;
    }
    int j = 0;
    for(int i = 1; i < patternsize; i++){
        //비교하는 인덱스가 불일치할 경우
        while(j > 0 && kmppattern[i] != kmppattern[j]){
            j = table[j - 1];
        }
        //일치하는 경우
        if(kmppattern[i] == kmppattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}
//KMP 함수
void KMP(char* kmpparent, char* kmppattern){
    int* table = MakeTable(kmppattern);
    int parentnsize = strlen(kmpparent);
    int patternsize = strlen(kmppattern);
    int j = 0;

    for(int i = 0; i < parentnsize; i++){
        //불일치할 경우
        while(j > 0 && kmpparent[i] != kmppattern[j]){
            j = table[j - 1];
        }
        //일치하였을 경우
        if(kmpparent[i] == kmppattern[j]){
            //pattern의 문자열의 길이만큼 일치하였을 경우
            if(j == patternsize - 1){
                printf("found %d`s index\n", i - patternsize + 2);// i - patternsize = 일치하기 시작한 index - 1
                j = table[j];
            }
            else{
                j++;
            }
        }
    }
}
void main(){
    //SimpleMatching();
    KMP(kmpparent, kmppattern);
}