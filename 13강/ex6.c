#include <stdio.h>

int main(void) {
	int a[5] = {1, 2, 3, 4, 5};
	int *p = a;
	printf("%d\n", *(p++)); // 1
	printf("%d\n", *(++p)); // 3
	printf("%d\n", *(p + 2)); // 5
	system("pause");
	return 0;
}