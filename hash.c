#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TABLE_SIZE 101
//#define INPUT_SIZE 20
//학생 정보를 담을 구조체
typedef struct Student
{
    int id;
    char name[20];
}Student;
//해시 테이블 초기화
void Init(Student** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashtable[i] = NULL;
    }
}
//해시 테이블 할당 해제
void Destructor(Student** hashtable){
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashtable[i] != NULL){
            free(hashtable[i]);
        }
    }
}
//테이블의 빈 공간을 선형 탐색으로 찾아주는 함수
int FindEmpty(Student** hashtable, int id){
    int i = id % TABLE_SIZE;
    while(1){
        if(hashtable[i] == NULL){
            return i;
        }
        i++;
    }
}
//id 값에 매칭되는 데이터를 찾는 함수
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
//키에 데이터 삽입
void Add(Student** hashtable, Student* input, int key){
    hashtable[key] = input;
}
//키의 데이터 반환
Student* GetValue(Student** hashtable, int key){
    return hashtable[key];
}
//테이블 내 모든 데이터 출력
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
        sprintf(student->name, "사람%d", student->id);

        if(Search(hashtable, student->id) == -1){
            int index = FindEmpty(hashtable, student->id);
            Add(hashtable, student, index);
        }
    }

    Show(hashtable);
    Destructor(hashtable);
}