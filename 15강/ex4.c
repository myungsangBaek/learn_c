#include <stdio.h>

int add(int a, int b){
	return a + b;
}

int (*process char* a))(int, int) {
	printf("%s\n", a);
	return add;
}

int main(void){
	printf("%d\n", process("10과 20을 더한 값을 출력")(10, 20));
	system("pause")
	return 0;
}