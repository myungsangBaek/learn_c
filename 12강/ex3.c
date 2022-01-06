#include <stdio.h>

void process(){
	static int a = 5;
	a = a + 1;
	printf("%d\n", a);
}

int main(void) {
	process();
	process();
	process();
	system("pause");
	return 0;
}
// 6, 7, 8