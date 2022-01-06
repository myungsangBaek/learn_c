#include <stdio.h>
#include <limits.h>

int main(void) {
	int a[10] = { 6, 5, 4, 3, 9, 8, 0, 1, 2, 7 };
	int i, maxValue = INT_MIN;
	for (i = 0; i < 10; i++){
		if (maxValue < a[i]) maxValue = a[i];
	}
	printf("%d\n", maxValue);
	system("pause")
	return 0;
}