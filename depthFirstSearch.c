#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int index;
    struct Node* next;
}Node;


//stack������ Node ����
void addNode(Node* root, int idx){
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = idx;
    node->next = root->next;
    root->next = node;
}

//���� �켱 Ž�� �Լ�
void dfs(int x, Node** a, int* c){
    if(c[x]) return;//c[x]�� ���� ���(!=0) �湮�� ���̹Ƿ� Ż��
    
    
    c[x] = 1; //�湮�� �����Ƿ� c[x]�� ���� 1�� ����.
    printf("%d ", x);
    
    Node* cur = a[x]->next; //���� ������ �̾����� ���� cur�� ����

    while(cur != NULL){ 
        int next = cur->index; //cur�� index�� ��, ���� ������ �̾����� ���� index���� next�� ����
        dfs(next, a, c);//�Լ� ����
        cur = cur->next;
    }



    
    

}

void main(){
    int node, edge;
    printf("������ ������ ���� �Է��Ͻÿ�: ");
    scanf("%d %d", &node, &edge);
    
    Node** a = (Node**)malloc(sizeof(Node*) * node);//������ ���� 2���� �迭 ����
    int c[50] = {0, };
    //�Է¹��� node������ŭ ���� ����
    for(int i = 0; i < node; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }

    for(int i = 0; i < edge; i++){
        int x, y;
        printf("������ ������ �Է��ϼ���: ");
        scanf("%d %d", &x, &y);
        addNode(a[x], y);
        addNode(a[y], x);
    }
    dfs(0, a, c);

}