#include <stdio.h>
#include <string.h>

char* parent = "acabacdabac";
char* pattern = "abacdab";

//parent ���ڿ��� pattern ���ڿ��� ��ġ�ϴ��� Ȯ��
void Check(char* parent, char* pattern, int start){
    int found = 1;
    int patternsize = strlen(pattern);
    //���ڿ� ��ġ Ȯ��
    for(int i = 0; i < patternsize; i++){
        if(parent[start + i] != pattern[i]){
            found = 0;
            break;
        }
    }
    //���ڿ��� ��ġ�Ͽ��� ���
    if(found){
        printf("%d���� ��Ī �߻�!\n", start + 1);
    }
}
//��� ī�� �˰���
void RabinKarp(char* parent, char* pattern){
    int parentsize = strlen(parent);
    int patternsize = strlen(pattern);
    //�� �ؽ��� 0���� �ʱ�ȭ, power = 2�� ������ --> �ʱ�ȭ�� 2^0
    int parenthash = 0, patternhash = 0, power = 1;
    
    for(int i = 0; i < parentsize - patternsize; i++){
        //�� Ȯ�� �ʱⰪ ����
        if(i == 0){
            for(int j = 0; j < patternsize; j++){
                parenthash += (parent[patternsize - 1 - j] * power);
                patternhash += (pattern[patternsize - 1 - j] * power);
                //�Ʒ� if ���� ���� ��� power�� ��ü ���ڿ� ���̺��� +1�� �������� �Ǿ����
                if(j < patternsize - 1) power *= 2;
            }
        }
        else{
            parenthash = 2 * (parenthash - parent[i - 1] * power) + parent[patternsize - 1 + i];
        }
        //�ؽ����� ��ġ �Ͽ��� ���
        if(parenthash == patternhash){
            Check(parent, pattern, i);
        }
    }
}

void main(){
    RabinKarp(parent, pattern);
}