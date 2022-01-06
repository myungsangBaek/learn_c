#include <stdio.h>

void add(int a, int b){
	a = a + b;
}

int main(void) {
	int a = 7;
	add(a, 10);
	printf("%d\n", a);
	system("pause");
	return 0;
}
// 7