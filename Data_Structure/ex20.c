//깊이 우선 탐색 

//연결 리스트 정의
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct {
    int index;
    struct Node *next;
} Node;

Node** a; //2차원 포인터
int n, m, c[MAX_SIZE];

//연결 리스트 삽입 함수
void addFront(Node *root, int index){
    Node *node = (Node*)malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

//깊이 우선 탐색 함수
void dfs(int x){
    if (c[x]) return;
    c[x] = 1;
    printf("%d ", x);
    Node *cur = a[x]->next;
    while (cur != NULL){
        int next = cur->index;
        dfs(next);
        cur = cur->next;
    }
}

//깊이 우선 탐색 이용
int main(void){
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE)); //정점의 갯수만큼 사이즈를 할당
    for (int i=1; i<=n; i++){
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for (int i = 0; i < m; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y); //x와 y를 연결
        addFront(a[y], x); 
    }
    dfs(1);
    system("pause");
    return 0;
}