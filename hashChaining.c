#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 7

typedef struct Student
{
    int id;
    char name[20];
}Student;

typedef struct Bucket
{
    Student* data;
    struct Bucket* next;
}Bucket;
//�ؽ� ���̺� �ʱ�ȭ
void Init(Bucket** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashtable[i] = NULL;
    }
}
//�ؽ� ���̺� �޸� ��ȯ
void Destructor(Bucket** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashtable[i] != NULL){
            free(hashtable[i]);
        }
    }
}
//ü�̴� ������ Ž�� �Լ�
int IsExist(Bucket** hashtable, int id){
    int i = id % TABLE_SIZE;
    if(hashtable[i] == NULL) return 0;//���̺��� ������ ���
    else{ //���̺� �����Ͱ� �������
        Bucket* cur = hashtable[i];
        while (cur != NULL){
            if(cur->data->id == id) return 1;
            cur = cur->next;
        }
    }
    return 0;
}
//ü�̴� ������ ���� �Լ�
void Add(Bucket** hashtable, Student* input){
    int i = input->id % TABLE_SIZE;
    if(hashtable[i] == NULL){//���̺� ���� �����Ͱ� �������
        hashtable[i] = (Bucket*)malloc(sizeof(Bucket));
        hashtable[i]->data = input;
        hashtable[i]->next = NULL;
    }
    else{//���̺� ���� �����Ͱ� ���� ���
        Bucket* cur = (Bucket*)malloc(sizeof(Bucket));
        cur->data = input;
        cur->next = hashtable[i];//cur->next�� ����Ű�� ��ġ�� hashtable[i]�� ���� ����� �����ͷ� ����
        hashtable[i] = cur; //cur�� ������ hashtable[i]�� ����
    }//ex)41�� hastable[6]�� �̹� ����� �� 34�� ���´ٸ� 34->41�� �����Ų��.
}
//ü�̴� ������ ��� �Լ�
void Show(Bucket** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashtable[i] != NULL){
            Bucket* cur = hashtable[i];
            while (cur != NULL){
                printf("key: [%d] Name: [%s]\n", i, cur->data->name);
                cur = cur->next;
            }
        }
    }
}

void main(){
    Bucket** hashtable;
    hashtable = (Bucket**)malloc(sizeof(Bucket*) * TABLE_SIZE);
    Init(hashtable);

    for(int i = 0; i < TABLE_SIZE; i++){
        Student* student = (Student*)malloc(sizeof(Student));
        student->id = rand() % 100;
        sprintf(student->name, "��� %d", student->id);
        if(!IsExist(hashtable, student->id)){//IsExist�Լ��� return ���� 0�� ���
            Add(hashtable, student);
        }
    }

    Show(hashtable);
    Destructor(hashtable);
}