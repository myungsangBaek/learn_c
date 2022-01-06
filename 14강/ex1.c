#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *a = malloc(sizeof(int));
	printf("%d\n", a);
	a = malloc(sizeof(int));
	printf("%d\n", a);
	system("pause");
	return 0;
}