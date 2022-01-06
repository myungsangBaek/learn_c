#include <stdio.h>

int main(void){
	register int a = 10, i;
	for (i = 0; i < a; i++){
		printf("%d ", i);
	}
	system("pause");
	return 0;
}
//0, 1, 2, 3, 4, 5, 6, 7, 8, 9