#include <stdio.h>
#define NUMBER 7

int g_arr[] = {7, 1, 9, 5, 3, 4, 1};
int g_tree[4 * NUMBER];

/*���� �� Ʈ�� ����*/
//start: ���� �ε���, end: �� �ε���
int Init(int start, int end, int node){
    if(start == end) return g_tree[node] = g_arr[start];
    int mid = (start + end) / 2;
    //��� �Լ��� ���� �� �κ����� ������ �� ���� �ڱ� �ڽ����� �Ѵ�
    return g_tree[node] = Init(start, mid, node * 2) + Init(mid + 1, end, node * 2 + 1);
}

/*���� �� ���*/
//left, right: ���� ���� ���ϰ��� �ϴ� ����
int Sum(int start, int end, int node, int left, int right){
    //���� �ۿ� �ִ� ���
    if(left > end || right < start) return 0;
    //���� �ȿ� �ִ� ���
    if(left <= start && right >= end) return g_tree[node];
    //�׷��� �ʴٸ� �� �κ����� ������ ���� ���Ѵ�.
    int mid = (start + end) / 2;
    return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
}

/*���� ����*/
//start: ���� �ε���, end: �� �ε���
//index: ���� ���� �����ϰ��� �ϴ� ���
//dif: ������ ��
void Updata(int start, int end, int node, int index, int dif){
    //���� �ۿ� �ִ� ���
    if(index < start || index > end) return;
    //���� �ȿ� ������ �������� �ٸ� ���ҵ� ����
    g_tree[node] += dif;
    if(start == end) return;//���� ����� ���� ��忡 ���������Ƿ� Ż��
    int mid = (start + end) / 2;
    Updata(start, mid, node * 2, index, dif);
    Updata(mid + 1, end, node * 2 + 1, index, dif);
}

void main(){
    //���� �� Ʈ�� ����
    Init(0, NUMBER - 1, 1);
    //���� �� ���ϱ�
    printf("0~6������ ���� ��: %d\n", Sum(0, NUMBER - 1, 1, 0, 6));
    
    printf("�ε��� 3�� ���Ҹ� + 2 ��ŭ ����\n");
    Updata(0, NUMBER - 1, 1, 3, 2);

    printf("������ 2~6������ ���� ��: %d\n", Sum(0, NUMBER - 1, 2, 0, 6));
}