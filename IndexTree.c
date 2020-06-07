#include <stdio.h>
#define NUMBER 7

int g_tree[NUMBER];
//1~N������ �������� ���ϴ� �Լ�
int Sum(int index){
    int result = 0;
    while(index > 0){
        result += g_tree[index];
        //������ ��Ʈ��ŭ ���� ������ ����.
        index -= (index & -index);
    }
    return result;
}
//Ư�� �ε��� ����
void Updata(int index, int dif){
    while(index <= NUMBER){
        g_tree[index] += dif;
        //������ ��Ʈ��ŭ �����ش�.
        index += (index & -index);
    }
}
//���� �� ��� �Լ�
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
    printf("1~7������ ������ : %d\n", GetSection(1, 7));
    printf("�ε��� 6�� ���Ҹ� 2��ŭ ����\n");
    Updata(6, 2);
    printf("1~7������ ������ : %d\n", GetSection(1, 7));
    printf("2~5������ ������ : %d\n", GetSection(2, 5));
}


