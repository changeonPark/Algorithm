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
            printf("%d��°���� ã��!\n", i + 1);
            break;
        }
    }
    if(!found){
        printf("ã�� �� ����!\n");
    }
}

char* kmpparent = "acabacdabac";
char* kmppattern = "cdabac";
//���̺� ���� �Լ�
int* MakeTable(char* kmppattern){
    int patternsize = strlen(kmppattern);
    int* table = (int*)malloc(sizeof(int) * patternsize);//table�� ���� = ������ ���� --> �޸� �Ҵ�
    //table �迭 0���� �ʱ�ȭ
    for(int i = 0; i < patternsize; i++){
        table[i] = 0;
    }
    int j = 0;
    for(int i = 1; i < patternsize; i++){
        //���ϴ� �ε����� ����ġ�� ���
        while(j > 0 && kmppattern[i] != kmppattern[j]){
            j = table[j - 1];
        }
        //��ġ�ϴ� ���
        if(kmppattern[i] == kmppattern[j]){
            table[i] = ++j;
        }
    }
    return table;
}
//KMP �Լ�
void KMP(char* kmpparent, char* kmppattern){
    int* table = MakeTable(kmppattern);
    int parentnsize = strlen(kmpparent);
    int patternsize = strlen(kmppattern);
    int j = 0;

    for(int i = 0; i < parentnsize; i++){
        //����ġ�� ���
        while(j > 0 && kmpparent[i] != kmppattern[j]){
            j = table[j - 1];
        }
        //��ġ�Ͽ��� ���
        if(kmpparent[i] == kmppattern[j]){
            //pattern�� ���ڿ��� ���̸�ŭ ��ġ�Ͽ��� ���
            if(j == patternsize - 1){
                printf("found %d`s index\n", i - patternsize + 2);// i - patternsize = ��ġ�ϱ� ������ index - 1
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