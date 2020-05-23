#include <stdio.h>

//�Է� ���� �� ���� �ٲٱ� ���� �Լ�
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct priorityQueue
{
    int heap[10]; //�Էµ� ���� ���� �迭
    int count;//�Էµ� ���� ���� ���� ����
}priorityQueue;

//ť ����
void push(priorityQueue* pq, int data){
    //������ ���� �̻����� �Է��Ϸ� �� ���
    if(pq->count >= 10){
        printf("stack overflow\n");
        return;
    }

    pq->heap[pq->count] = data;
    //Ʈ������ ���� ��ġ
    int now = pq->count;
    //�θ� Ʈ���� ã�� ���� ��
    int parent = (now - 1) / 2;
    //��������� heap ���� . ó�� ���� pq->heap[0]�� ����, 2��° ���� �θ𰪰� ���Ͽ� ���� ���� �� ��ü
    //��������� sort
    while (now > 0 && pq->heap[now] > pq->heap[parent])
    {
        swap(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;//count�� ������Ų�� -> ���� ���� �����Ƿ�
}

//ť ���� -->>FIFO�̹Ƿ� ���� �� ���� ���� ������.
int pop(priorityQueue* pq){
    //�Է¹��� ���� ���� �� �����Ϸ� �� ���
    if(pq->count <= 0){
        printf("stack underflow\n");
        return -9999;
    }

    int result = pq->heap[0];
    pq->count--; //�迭�� 0���� ���� --> count--�� ���־�� ������ ���� ��ġ�� �°� �ȴ�.
    pq->heap[0] = pq->heap[pq->count];//���� ����� ���� ��Ʈ ��忡 �ִ´�.
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now;

    //��������� ���� �����Ѵ�.
    //��������� sort
    while(leftchild < pq->count){
        if(pq->heap[target] < pq->heap[leftchild]) target = leftchild; //���� ���� ���� �ڽ� ��� ���� ���� ���
        if(pq->heap[target] < pq->heap[rightchild] && rightchild < pq->count) target = rightchild;
        if(target == now) break;
        else{
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftchild = now * 2 + 1;
            rightchild = now * 2 + 2;
        }
    }
    return result;
}

void main(){
    int n, data;
    scanf("%d", &n);
    priorityQueue pq;
    pq.count = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", & data);
        push(&pq, data);
    }

    for(int i = 0; i < n; i++){
        int pdata = pop(&pq);
        printf("%d ", pdata);
    }
}