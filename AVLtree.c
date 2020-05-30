#include <stdio.h>
#include <stdlib.h>
#include <math.h>//abs() << ���밪 �Լ�

typedef struct Node
{
    int data;
    int height;//���̸� �����ؾ� �ð� ���⵵ ���� ����.
    struct Node* leftchild;
    struct Node* rightchild;
}Node;
//���� ����� ���̸� ��ȯ�ϴ� �Լ�
int getHeight(Node* node){
    if(node == NULL) return 0;
    return node->height;
}
//�� �� �� ū ���� ��ȯ�����ִ� �Լ� setHeight���� �����.
int getMax(int a, int b){
    if(a > b) return a;
    else return b;
}
//ȸ�� �� ���̸� �ٽ� ����� �� ����� �Լ� --> ���� �ڽ��� ���� vs ������ �ڽ��� ���� -> winner + 1
void setHeihgt(Node* node){
    node->height = getMax(getHeight(node->leftchild), getHeight(node->rightchild)) + 1;
}
//LLȸ��: ���� �ڽ� ����� ���ʿ� ������ �߻��Ͽ��� ��� => ��ȸ��
Node* rotateLL(Node* node){
    Node* leftchild = node->leftchild;
    node->leftchild = leftchild->rightchild;
    leftchild->rightchild = node;
    setHeihgt(node);
    return leftchild;
}
//RRȸ��: ������ �ڽ��� ����� �����ʿ� ������ �߻��Ͽ��� ��� => ��ȸ��
Node* rotateRR(Node* node){
    Node* rightchild = node->rightchild;
    node->rightchild = rightchild->leftchild;
    rightchild->leftchild = node;
    setHeihgt(node);
    return rightchild;
}
//LRȸ��: ���� �ڽ��� ����� �����ʿ� ������ �߻��Ͽ��� ��� ==> �ڽ� ��忡������ ��ȸ�� �� ��忡������ ��ȸ��
Node* rotateLR(Node* node){
    Node* leftchild = node->leftchild;
    node->leftchild = rotateRR(leftchild);
    return rotateLL(node);
}
//RLȸ��: ������ �ڽ��� ����� ���ʿ� ������ �߻��Ͽ��� ��� ==> �ڽ� ��忡������ ��ȸ�� �� ��忡������ ��ȸ��
Node* rotateRL(Node* node){
    Node* rightchild = node->rightchild;
    node->rightchild = rotateLL(rightchild);
    return rotateRR(node);
}
//���� �μ�(Balance Factor)�� ���ϴ� �Լ�
int getDifference(Node* node){
    if(node == NULL) return 0;
    Node* leftchild = node->leftchild;
    Node* rightchild = node->rightchild;
    return getHeight(leftchild) - getHeight(rightchild);
}
//AVLƮ���� ������ ���ߴ� �Լ�
Node* balance(Node* node){
    int diff = getDifference(node);
    if(diff >= 2){//���� �ڽ� ����ʿ��� ������ ���
        if(getDifference(node->leftchild) >= 1){
            node = rotateLL(node);
        }
        else{
            node = rotateLR(node);
        }
    }
    else if (diff <= -2){//������ �ڽ� ����ʿ��� ������ ���
        if(getDifference(node->rightchild) <= -1){
            node = rotateRR(node);
        }
        else{
            node = rotateRL(node);
        }
    }
    setHeihgt(node);//ȸ�� �� ���� ����
    return node;
}
//���� �Լ�
Node* insert(Node* node, int data){
    if(!node){//��� ����
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->height = 1;
        node->leftchild = node->rightchild = NULL;
    }
    else if(data < node->data){//���� �ڽ����� �̵�
        node->leftchild = insert(node->leftchild, data);
        node = balance(node);
    }
    else if(data > node->data){
        node->rightchild = insert(node->rightchild, data);
        node = balance(node);
    }
    else{
        printf("������ �ߺ��Դϴ�!\n");
    }
    return node;
}

Node* root = NULL;//root�� ���� ����� Node ����
//��°��� ������ �Լ�
void display(Node* node, int level){
    if(node != NULL){
        display(node->rightchild, level + 1);//�ֿ����� ������ ���
        printf("\n");
        if(node == root){
            printf("Root: ");
        }
        for(int i = 0; i < level && node != root; i++){
            printf("     ");
        }
        printf("%d(%d)", node->data, getHeight(node));
        display(node->leftchild, level+1);//���� ���� �̵�
    }
}

void main(){
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 18);
    root = insert(root, 23);
    root = insert(root, 21);
    root = insert(root, 14);
    root = insert(root, 15);
    root = insert(root, 19);
    root = insert(root, 20);
    display(root, 1);
    printf("\n");
}