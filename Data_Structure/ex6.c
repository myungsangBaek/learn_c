//스택의 정의

#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char data[100];
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
} Stack;

//스택 함수 구현
void push(Stack *stack, char data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

char* getTop(Stack *stack){
    Node *top = stack->top;
    return top->data;
}

char* pop(Stack *stack){
    if(stack->top == NULL){
        printf("스택 언더플로우가 발생했습니다.\n");
        return -INF;
    }
    Node *node = stack->top;
    char *data = node->data;
    strcpy(data, node->data);
    stack->top = node->next;
    free(node);
    return data;
}

int getPriority(char *i){
    if (!strcmp(i, "(")) return 0;
    if (!strcmp(i, "+") || !strcmp(i, "-")) return 1;
    if (!strcmp(i, "*") || !strcmp(i, "/")) return 2;
    return 3;
}

//후위 표기법으로 변환

char* transition(Stack *stack, char **s, int size){
    char res[1000] = "";
    for (int i = 0; i < size; i++){
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*" || !strcmp(s[i], "/")){
            while (stack->top != NULL && getPriority(getTop(stack)) >= getPriority(s[i])){
                strcat(res, pop(stack)); strcat(res,"");
            }
            push(stack, s[i]);
        }
        else if (!strcmp(s[i], "(")) push(stack, s[i]);
        else if (!strcmp(s[i], ")")){
            while (strcmp(getTop(stack), "(")){
                strcat(res, pop(stack)); strcat(res, "");
            }
            pop(stack);
        }
        else { strcat(res, s[i]; strcat(res, "");}
    }
    while (stack->top != NULL){
        strcat(res, pop(stack)); strcat(res, "");
    }
    return res;
}

void calculate(Stack *stack, char **s, int size){
    int x, y, z;
    for(int i = 0; i < size; i++){
        if (!strcmp(s[i], "+") || !strcmp(s[i], "-") || !strcmp(s[i], "*") || !strcmp(s[i], "/")){
            x = atoi(pop(stack));
            y = atoi(pop(stack));
            if (!strcmp(s[i], "+")) z = y + x;
            if (!strcmp(s[i], "-")) z = y - x;
            if (!strcmp(s[i], "*")) z = y * x;
            if (!strcmp(s[i], ".")) z = y / x;
            char buffer[100];
            sprintf(buffer, "%d", z);
            push(stack, buffer);
        }
        else {
            push(stack, s[i]);
        }
    }
    printf("%s\n", pop(stawck));
}

void push