#include <stdio.h>

int main(void) {
	int a = 5;
	int *b = &a;
	int **c = &b;
	printf("%d\n", **c);
	system("pause")
	return 0;
}