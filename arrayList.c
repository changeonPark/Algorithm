#include <stdio.h>
#define INF 10000
/*
�迭 ��� ����Ʈ -> �����͸� ���������� ���� �� ó���� ���.
����: Ư���� ��ġ�� ���ҿ� ��� ���� ����
����: �����Ͱ� �� ���� �̸� �Ҵ� �ʿ�
      ���ϴ� ��ġ�� ����, ���� ��ȿ����
*/
int arr[INF];
int cnt = 0;

void addBack(int data){
    arr[cnt] = data; //�Է¹��� �� �迭�� ����.
    printf("%d ", arr[cnt]); //Ȯ�ο�
    cnt++;
}

void addFirst(int data){
//�� ������ �� �� �������� �ݺ�.
    for(int i = cnt; i>=1; i--){
        arr[i] = arr[i - 1]; //���ڸ��� ��ĭ�� �о��ش�.
    }
    arr[0] = data; //0��°�� �Է¹��� ������ ����
    printf("%d ", arr[0]); //Ȯ�ο�
    cnt++;
}

void show(){
    for(int i = 0; i < cnt; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delIndex(){
    int num;
    int check = 0; // �Է¹��� ���� �迭�� ũ�⺸�� ū�� Ȯ��.
    printf("\n����� ���� �ڸ��� �Է��ϼ���: ");
    scanf("%d", &num);
    for(int i = (cnt -1); i >= 0; i--){//�迭 �ǳ����� 0��°���� �ݺ�.
        if(num == i){ // �Է� ���� ���� �迭�ȿ� ���� ���
            for(int j = num; j < cnt - 1; j++){//
                arr[j] = arr[j + 1];
            }
            cnt --; //cnt�� �� �Էµ� �迭���� 1 ũ��, ��ĭ�� ��������Ƿ� 1 ����.
            check = 0; //��
        }
        check = 1; //����
    }
    if( check == 0){}
    else{
        printf("Not Index\n");
    }
}

void main(){
    addBack(10);
    addBack(9);
    addBack(8);
    addBack(7);
    delIndex();
    addFirst(6);
    addFirst(5);
    show();
}