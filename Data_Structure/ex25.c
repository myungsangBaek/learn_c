//체이닝 구조체 정의
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000 //무작위 데이터 5000개

typedef struct {
    int id;
    char name[20];
} Student;

typedef struct{
    Student* data;
    struct Bucket* next;
}Bucket;

//초기화
void init(Bucket** hashTable){
	for (int i = 0; i < TABLE_SIZE; i++){
		hashTable[i] = NULL;
	}
}

//해시 테이블의 메모리를 반환
void destuctor(Bucket** hashTable){
	for(int i = 0; i < TABLE_SIZE; i++){
		if(hashTable[i] != NULL){
			free(hashTable[i]);
		}
	}
}

// 체이닝 데이터 탐색 함수

int isExist(Bucket** hashTable, int id){
    int i = id % TABLE_SIZE;
    if(hashTable[i] == NULL) return 0;
    else {
        Bucket *cur = hashTable[i];
        while(cur != NULL){
           if (cur->data->id == id) return 1;
            cur = cur->next;
        }
    }
    return 0;
}

// 특정한 키 인덱스에 데이터를 삽입
void add(Bucket** hashTable, Student* input){
    int i = input->id % TABLE_SIZE;
    if(hashTable[i] == NULL){
        hashTable[i] = (Bucket*)malloc(sizeof(Bucket));
        hashTable[i]->data = input;
        hashTable[i]->next = NULL;
    }
    else{
        Bucket *cur = (Bucket*)malloc(sizof(Bucket));
        cur->data = input;
        cur->next = hashTable[i];
        hashTable[i] = cur;
    }
}

//해시 테이블에 존재하는 모든 데이터를 출력한다.
void show(Bucket** hashTable){
    for (int i = 0; i < TABLE_SIZE; i++){
        if(hashTable[i] != NULL){
            Bucket *cur = hashTable[i];
            while (cur != NULL){
                printf("키: [%d] 이름: [%s]\n", i, cur->data->name);
                cur = cur->next;
            }
        }
    }
}

int main(void){
    Bucket **hashTable;
    hashTable = (Bucket**)malloc(sizeof(Bucket) * TABLE_SIZE);
    init(hashTable);

    for (int i = 0; i < INPUT_SIZE; i++){
        Student* student = (Student*)malloc(sizeof(Student));
        student->id = rand() % 1000000;
        sprintf(student->name, "사람%d", student->id);
        if(!isExist(hashTable, student->id)){ //중복되는 ID는 존재하지 않도록 함.
            add(hashTable, student);
        }
    }

    show(hashTable);
    destuctor(hashTable);
    system("pause");
    return 0;
}