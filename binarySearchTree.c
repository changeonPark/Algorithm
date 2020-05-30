#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* leftchild;
    struct Node* rightchild;
}Node;
//��� ���� �Լ�
Node* insert(Node* root, int data){
    if(root == NULL){//��� ����
        root = (Node*)malloc(sizeof(Node));
        root->leftchild = root->rightchild = NULL;
        root->data = data;
        return root;
    }
    else{
        if(root->data > data){//���� �߰��� ��尡 ���� ��庸�� ���� ���
            root->leftchild = insert(root->leftchild, data);
        }
        else{//���� �߰��� ��尡 ���� ��庸�� ū ���
            root->rightchild = insert(root->rightchild, data);
        }
    }
    return root;
}
//���� ��ȸ �Լ�
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->leftchild);
    printf("%d ", root->data);
    inorder(root->rightchild);
}
//Ư�� ������ ū ���� ���� ���� ���� ã�´�.
Node* findMin(Node* root){
    Node* node = root;
    while(node->leftchild != NULL) node = root->leftchild;
    return node;
}

Node* delete(Node* root, int data){
    Node* node = NULL;//null�ʱ�ȭ �ʼ�: ���� �ڽ��� ���� ��� null���� ��ȯ�ؾ� �ϹǷ�
    if(root == NULL) return NULL;
    
    //������ ���ǵ��� ��� �Ҹ��� �� ������ ���� �״�� ��ȯ�Ѵ�.
    if(root->data > data) root->leftchild = delete(root->leftchild, data);
    else if(root->data < data) root->rightchild = delete(root->rightchild, data);
    else{//���� ���� ������� ���� ��ġ�� ���
        if(root->leftchild != NULL && root->rightchild != NULL){//���� �ڽ��� ��� �ִ�
            node = findMin(root->rightchild);//���� ��� �� �ּڰ��� ã�´�
            root->data = node->data;//�ּڰ��� ������� ���� ��ġ�� �̵�
            root->rightchild = delete(root->rightchild, node->data);//�ּڰ� ����
        }
        else{
            node = (root->leftchild != NULL) ? root->leftchild : root->rightchild;
            free(root);
            return node;
        }
    }
    return root;
}

void main(){
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 17);
    root = insert(root, 48);
    root = insert(root, 5);
    root = insert(root, 23);
    root = insert(root, 37);
    root = insert(root, 50);
    root = delete(root, 17);
    inorder(root);
}
