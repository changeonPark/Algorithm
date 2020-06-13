#include <stdio.h>
#include <string.h>

char* parent = "acabacdabac";
char* pattern = "abacdab";

//parent 문자열과 pattern 문자열이 일치하는지 확인
void Check(char* parent, char* pattern, int start){
    int found = 1;
    int patternsize = strlen(pattern);
    //문자열 일치 확인
    for(int i = 0; i < patternsize; i++){
        if(parent[start + i] != pattern[i]){
            found = 0;
            break;
        }
    }
    //문자열이 일치하였을 경우
    if(found){
        printf("%d에서 매칭 발생!\n", start + 1);
    }
}
//라빈 카프 알고리즘
void RabinKarp(char* parent, char* pattern){
    int parentsize = strlen(parent);
    int patternsize = strlen(pattern);
    //각 해쉬값 0으로 초기화, power = 2의 제곱근 --> 초기화는 2^0
    int parenthash = 0, patternhash = 0, power = 1;
    
    for(int i = 0; i < parentsize - patternsize; i++){
        //비교 확인 초기값 설정
        if(i == 0){
            for(int j = 0; j < patternsize; j++){
                parenthash += (parent[patternsize - 1 - j] * power);
                patternhash += (pattern[patternsize - 1 - j] * power);
                //아래 if 문이 없을 경우 power가 전체 문자열 길이보다 +1된 제곱근이 되어버림
                if(j < patternsize - 1) power *= 2;
            }
        }
        else{
            parenthash = 2 * (parenthash - parent[i - 1] * power) + parent[patternsize - 1 + i];
        }
        //해쉬값이 일치 하였을 경우
        if(parenthash == patternhash){
            Check(parent, pattern, i);
        }
    }
}

void main(){
    RabinKarp(parent, pattern);
}