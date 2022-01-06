#include <stdio.h>

int main(void){
	char a[20] = "Han";
	char b[20] = "Robert";
	strcpy(a, b);
	printf("복사된 문자열:%s\n", a);
	system("pause")
	return 0;
}