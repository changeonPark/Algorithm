#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int index;
    struct Node* next;
}Node;



void addNode(Node* root, int idx){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = idx;
    node->next = root->next;
    root->next = node;
}

void dfs(int x, Node** a, int* c){
    if(c[x]) {
        printf("check c[x] : %d\n", c[x]);
        return;
    }
    c[x] = 1;
    printf("%d ", x);
    
    Node* cur = a[x]->next;

    while(cur != NULL){
        int next = cur->index;
        dfs(next, a, c);
        cur = cur->next;
    }



    
    

}

void main(){
    int node, edge;
    printf("정점과 간선의 수를 입력하시오: ");
    scanf("%d %d", &node, &edge);
    
    Node** a = (Node**)malloc(sizeof(Node*) * node);//정점을 담을 2차원 배열 생성
    int c[50] = {0, };
    //입력받은 node변수만큼 정점 생성
    for(int i = 0; i < node; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }

    for(int i = 0; i < edge; i++){
        int x, y;
        printf("연결할 노드들을 입력하세요: ");
        scanf("%d %d", &x, &y);
        addNode(a[x], y);
        addNode(a[y], x);
    }
    dfs(0, a, c);

}