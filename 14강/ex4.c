#include <stdio.h>
#include <stdlib.h>

int main(void){
	int **p = (int**)malloc(sizeof(int*) * 3);
	for (int i = 0; i < 3; i ++) {
		*(p + i) = (int*)mallock(sizeof(int) * 3);
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++){
			*(*(p + i) + j ) = i * 3 + j;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++){
			printf("%d ", *(*(p + i) + j));
			}
			printf("\n");
		}
		system("pause");
		return 0;
	}
// 0 1 2
// 3 4 5
// 6 7 8