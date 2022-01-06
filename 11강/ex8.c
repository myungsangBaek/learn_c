#include <stdio.h>

int main(void){
	char a[30] = "Han";
	char b[20] = "Robert";
	strcat(a, b);
	printf("합쳐진 결과 문자열:%s\n", a);
	system("pause")
	return 0;
}