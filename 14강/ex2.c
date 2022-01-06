#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *a = malloc(sizeof(int));
	printf("%d\n", a);
	free(a);
	a = malloc(sizeof(int));
	printf("%d\n", a);
	free(a);
	system("pause");
	return 0;
}
// 동일한 주소값 출력