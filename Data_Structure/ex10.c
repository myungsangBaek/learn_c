//삽입 정렬 배열 선언
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//삽입 정렬 수행하기

int main(void){
    int n, min, index;
    scanf("%d", &n);
    for (int i = 0; i < n, i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n - 1; i++){
        int j = i;
        while(j>=0 && a[j] > a[j + 1]){
            swap(&a[j], &a[j + 1]);
            j--;
        }
    }
    for (int i = 0; i < n, i++){
        printf("%d ", a[i]);
    }
    system("pause")
}