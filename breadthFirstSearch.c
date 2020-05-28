#include <stdio.h>
#include <stdlib.h>

#define INF 99999
#define MAX 1000

//정점의 정보를 담을 Node struct
typedef struct Node
{
    int index;
    struct Node* next;
}Node;

//방문 정보를 담을 Queue struct
typedef struct Queue
{
    Node* front;
    Node* rear;
    int cnt;
}Queue;

Node** a;//각 정점이 인접한 정점들의 정보를 담을 2차원 포인터 배열
int node, edge, check[MAX];//정점의 수, 간선의 수, 각 정점 방문 확인용 배열

//정점에 대한 정보를 담을 노드를 생성하는 연결리스트 함수
void add(Node* root, int index){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void queuePush(Queue* queue, int index){
    //큐에 담을 정보를 저장하기 위한 노드
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = NULL;
    //큐에 최초로 데이터가 들어갈 경우
    if(queue->cnt == 0){
        queue->front = node;
    }
    else{//이미 큐에 데이터가 있을 경우 제일 끝 노드의 다음으로 연결
        queue->rear->next = node;
    }
    //rear가 가리키는 위치를 현재 생성한 노드를 가리키게 해준다
    queue->rear = node;
    //큐에 새로운 노드가 추가되었으므로 cnt를 증가시켜준다
    queue->cnt++;
}

int queuePop(Queue* queue){
    //큐에 아무런 데이터도 없을 경우
    if(queue->cnt == 0){
        printf("queue underflow!\n");
        return -INF;
    }
    //큐에 데이터가 있을 경우
    //큐의 정보를 저장할 노드를 생성해 front가 가리키는 노드의 정보를 담는다.
    Node* node = queue->front;
    //index변수에 node에 저장된 index의 값을 저장한다(반환하기 위함)
    int index = node->index;
    queue->front = node->next;
    free(node);
    queue->cnt--;
    return index;
}

void bfs(int start){
    //큐 초기화
    Queue que;   
    que.front = que.rear = NULL;
    que.cnt = 0;
    //큐에 데이터 추가
    queuePush(&que, start);
    //start번째 정점 방문 처리
    check[start] = 1;

    //que에 모든 데이터가 빠질 때 까지 반복한다
    while(que.cnt != 0){
        //방문한 노드 추출 후 출력
        int x = queuePop(&que);
        printf("%d ", x);
        //현재 방문한 노드의 다음 노드의 정보를 cur에 저장
        Node* cur = a[x]->next;
        //모든 노드를 방문할 때까지 반복
        while (cur != NULL)
        {
            //현재 노드의 index를 next에 저장
            int next = cur->index;
            //check[next] != 0 -->방문하지 않은 노드일 경우
            if (!check[next])
            {
                //큐에 추가해주고 방문처리 해준다.
                queuePush(&que, next);
                check[next] = 1;
            }
            cur = cur->next;        
        }
    }
}

void main(){
    printf("정점의 수와 간선의 수를 입력하세요: ");
    scanf("%d %d", &node, &edge);
    a = (Node**)malloc(sizeof(Node*) * MAX);

    for(int i = 0; i < node; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }

    for (int i = 0; i < edge; i++){
        int x, y;
        printf("연결할 두 정점을 입력하세요: ");
        scanf("%d %d", &x, &y);
        add(a[x], y);
        add(a[y], x);
    }
    bfs(0);
}