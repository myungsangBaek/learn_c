#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int i = 1;
	while (i <= 9) {
	printf("%d * %d = %d\n", n, i, n * i);
	i++;
}
	system("pause");
	return 0;
}