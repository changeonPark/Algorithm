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
//해시 테이블 초기화
void Init(Bucket** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashtable[i] = NULL;
    }
}
//해시 테이블 메모리 반환
void Destructor(Bucket** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashtable[i] != NULL){
            free(hashtable[i]);
        }
    }
}
//체이닝 데이터 탐색 함수
int IsExist(Bucket** hashtable, int id){
    int i = id % TABLE_SIZE;
    if(hashtable[i] == NULL) return 0;//테이블이 공백일 경우
    else{ //테이블에 데이터가 있을경우
        Bucket* cur = hashtable[i];
        while (cur != NULL){
            if(cur->data->id == id) return 1;
            cur = cur->next;
        }
    }
    return 0;
}
//체이닝 데이터 삽입 함수
void Add(Bucket** hashtable, Student* input){
    int i = input->id % TABLE_SIZE;
    if(hashtable[i] == NULL){//테이블 내에 데이터가 없을경우
        hashtable[i] = (Bucket*)malloc(sizeof(Bucket));
        hashtable[i]->data = input;
        hashtable[i]->next = NULL;
    }
    else{//테이블 내에 데이터가 있을 경우
        Bucket* cur = (Bucket*)malloc(sizeof(Bucket));
        cur->data = input;
        cur->next = hashtable[i];//cur->next가 가리키는 위치를 hashtable[i]에 현재 저장된 데이터로 지정
        hashtable[i] = cur; //cur의 정보를 hashtable[i]에 저장
    }//ex)41이 hastable[6]에 이미 저장된 후 34가 들어온다면 34->41로 연결시킨다.
}
//체이닝 데이터 출력 함수
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
        sprintf(student->name, "사람 %d", student->id);
        if(!IsExist(hashtable, student->id)){//IsExist함수의 return 값이 0일 경우
            Add(hashtable, student);
        }
    }

    Show(hashtable);
    Destructor(hashtable);
}