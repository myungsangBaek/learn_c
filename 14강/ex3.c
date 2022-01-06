#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char *a = malloc(100);
	memset(a, 'A' , 100);
	for (int i = 0; i <100; i++){
		printf("%c ", a[i]);
	}
	system("pause");
	return 0;
}
// A * 100개 출력