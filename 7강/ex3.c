#include <stdio.h>

void calculator(int a, int b) {
	printf("%d + %d = %d\n", a, b, a+b);
	printf("%d - %d = %d\n", a, b, a-b);
	printf("%d * %d = %d\n", a, b, a*b);
	printf("%d / %d = %d\n", a, b, a/b);
	printf("\n");
}

int main(void){
	calculator(10, 3);
	calculator(15, 2);
	calculator(18, 4);
	system("pause");
	return 0;
}