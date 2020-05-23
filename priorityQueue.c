#include <stdio.h>

//입력 받은 두 값을 바꾸기 위한 함수
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct priorityQueue
{
    int heap[10]; //입력된 수를 담을 배열
    int count;//입력된 수를 세기 위한 변수
}priorityQueue;

//큐 삽입
void push(priorityQueue* pq, int data){
    //저장할 공간 이상으로 입력하려 할 경우
    if(pq->count >= 10){
        printf("stack overflow\n");
        return;
    }

    pq->heap[pq->count] = data;
    //트리에서 현재 위치
    int now = pq->count;
    //부모 트리를 찾기 위한 식
    int parent = (now - 1) / 2;
    //상향식으로 heap 구성 . 처음 값은 pq->heap[0]에 저장, 2번째 부터 부모값과 비교하여 조건 성립 시 교체
    //상향식으로 sort
    while (now > 0 && pq->heap[now] > pq->heap[parent])
    {
        swap(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;//count값 증가시킨다 -> 값을 삽입 했으므로
}

//큐 추출 -->>FIFO이므로 먼저 들어간 값을 먼저 빼낸다.
int pop(priorityQueue* pq){
    //입력받은 수가 없을 때 추출하려 할 경우
    if(pq->count <= 0){
        printf("stack underflow\n");
        return -9999;
    }

    int result = pq->heap[0];
    pq->count--; //배열은 0부터 저장 --> count--를 해주어야 마지막 값의 위치에 맞게 된다.
    pq->heap[0] = pq->heap[pq->count];//리프 노드의 값을 루트 노드에 넣는다.
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now;

    //하향식으로 힙을 구성한다.
    //하향식으로 sort
    while(leftchild < pq->count){
        if(pq->heap[target] < pq->heap[leftchild]) target = leftchild; //현재 값이 왼쪽 자식 노드 보다 작을 경우
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