/* Use to Prim`s Algorithm */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define NODE_MAX 11 //1부터 시작할 것이므로 +1 
#define EDGE_MAX 201 //양방향 간선이므로 100개 x 2

//간선의 비용의 정보과 노드의 값을 담을 구조체
typedef struct Edge{
    int cost;
    int node;
}Edge;
//우선순위 큐 구조체
typedef struct PriorityQueue{
    Edge* heap[EDGE_MAX];
    int count;
}PriorityQueue;
//Node의 정보를 담을 구조체
typedef struct Node{
    Edge* data;
    struct Node* next;
}Node;
//x와 y의 값을 바꾸어줄 함수
void Swap(Edge* x, Edge* y){
    Edge temp;
    temp.cost = x->cost;
    temp.node = x->node;
    x->cost = y->cost;
    x->node = y->node;
    y->cost = temp.cost;
    y->node = temp.node;
}
/*우선 순위 큐*/
//큐 생성 함수
void Push(PriorityQueue* pq, Edge* edge){
    if(pq->count >= EDGE_MAX) return; //stack overflow
    pq->heap[pq->count] = edge;//heap의 맨 끝에 edge 저장
    int now = pq->count;
    int parent = (pq->count -1) / 2;
    //상향식으로 힙 구성 --> 최소 우선순위 큐
    while(now > 0 && pq->heap[now]->cost < pq->heap[parent]->cost){
        Swap(pq->heap[now], pq->heap[parent]);
        now = parent;
        parent = (parent -1) / 2;
    }
    pq->count++;
}
//큐 추출 함수
Edge* Pop(PriorityQueue* pq){
    if(pq->count <= 0) return NULL;//stack underflow
    Edge* result = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now;
    //하향식으로 구성--> 큰 수를 아래로 내린다.
    while(leftchild < pq->count){
        //현재 비용이 왼쪽 자식 비용보다 클 경우 왼쪽 자식으로 이동
        if(pq->heap[target]->cost > pq->heap[leftchild]->cost) target = leftchild;
        //현재 비용이 오른쪽 자식 비용보다 클 경우 오른쪽 자식으로 이동
        if(pq->heap[target]->cost > pq->heap[rightchild]->cost && rightchild < pq->count) target = rightchild;
        if(target == now) break;
        else{
            Swap(pq->heap[now], pq->heap[target]);
            now = target;
            leftchild = now * 2 + 1;
            rightchild = now * 2 + 2;
        }
    }
    return result;
}
/*간선 연결 리스트 구현*/
void AddNode(Node** target, int index, Edge* edge){
    if(target[index] == NULL){//첫 노드 생성
        target[index] = (Node*)malloc(sizeof(Node));
        target[index]->data = edge;
        target[index]->next = NULL;
    }
    else{
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = edge;
        node->next = target[index];
        target[index] = node;
    }
}
//프림 알고리즘 구현
Node** adj;
int arr[NODE_MAX];//각 정점 방문 여부 확인용 배열

void main(){
    int vertex, edge;
    printf("정점과 간선의 수를 입력하시오: ");
    scanf("%d %d", &vertex, &edge);
    adj = (Node**)malloc(sizeof(Node*) * (vertex + 1));
    for(int i = 1; i <= vertex; i++) adj[i] = NULL;
    //양방향 연결
    for(int i = 1; i <= edge; i++){
        printf("연결할 두 정점과 가중치를 입력하시오: ");
        int x, y, cost;
        scanf("%d %d %d", &x, &y, &cost);
        
        Edge* edge1 = (Edge*)malloc(sizeof(Edge));
        edge1->node = y;
        edge1->cost = cost;
        AddNode(adj, x, edge1);

        Edge* edge2 = (Edge*)malloc(sizeof(Edge));
        edge2->node = x;
        edge2->cost = cost;
        AddNode(adj, y, edge2);
    }
    //start prim`s Algorithm
    PriorityQueue* pq;
    pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->count = 0;

    long long res = 0;
    Edge* start = (Edge*)malloc(sizeof(Edge));
    start->cost = 0; start->node = 1;
    Push(pq, start);
    //start 먼저 실행 후 밑의 while문에서 node들의 정보를 불러온 후에 126의 while문 부터 실행한다.
    for(int i = 1; i <= vertex; i++){
        int nextnode = -1, nextcost = INT_MAX;
        while (1){
            Edge* now = Pop(pq);//1번째 노드를 추출해 now에 저장.
            if(now == NULL) break;
            nextnode = now->node;
            if(!arr[nextnode]){//arr[nextnode]에 방문한 전적이 없으면..
             nextcost = now->cost;
             break;
            }
        }
        if(nextcost == INT_MAX) printf("Not Linked Graph\n");
        res += nextcost;
        arr[nextnode] = 1;//방문 처리

        Node* cur = adj[nextnode];
        while (cur != NULL){
            Push(pq, cur->data);
            cur = cur->next;
        }  
    }
    printf("%lld\n", res);
}