#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 101
//#define INPUT_SIZE 20
//�л� ������ ���� ����ü
typedef struct Student
{
    int id;
    char name[20];
}Student;
//�ؽ� ���̺� �ʱ�ȭ
void Init(Student** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashtable[i] = NULL;
    }
}
//�ؽ� ���̺� �Ҵ� ����
void Destructor(Student** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashtable[i] != NULL){
            free(hashtable[i]);
        }
    }
}
//���̺��� �� ������ ���� Ž������ ã���ִ� �Լ�
int FindEmpty(Student** hashtable, int id){
    int i = id % TABLE_SIZE;
    while(1){
        if(hashtable[i] == NULL){
            return i;
        }
        i++;
    }
}
//id ���� ��Ī�Ǵ� �����͸� ã�� �Լ�
int Search(Student** hashtable, int id){
    int i = id % TABLE_SIZE;
    while(1){
        if(hashtable[i] == NULL){
            return -1;
        }
        else if(hashtable[i]->id == id){
            return i;
        }
        i++;
    }
}
//Ű�� ������ ����
void Add(Student** hashtable, Student* input, int key){
    hashtable[key] = input;
}
//Ű�� ������ ��ȯ
Student* GetValue(Student** hashtable, int key){
    return hashtable[key];
}
//���̺� �� ��� ������ ���
void Show(Student** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashtable[i] != NULL){
            printf("key: [%d] Name: [%s]\n", i+1, hashtable[i]->name);
        }
    }
}

void main(){
    Student** hashtable;
    hashtable = (Student**)malloc(sizeof(Student*) * TABLE_SIZE);
    Init(hashtable);

    for(int i = 0; i < TABLE_SIZE; i++){
        Student* student = (Student*)malloc(sizeof(Student));
        student->id = rand() % 100;
        sprintf(student->name, "���%d", student->id);

        if(Search(hashtable, student->id) == -1){
            int index = FindEmpty(hashtable, student->id);
            Add(hashtable, student, index);
        }
    }

    Show(hashtable);
    Destructor(hashtable);
}