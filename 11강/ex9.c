#include <stdio.h>

int main(void){
	char a[20] = "Han";
	char b[20] = "Robert";
	strcat(a, b);
	printf("찾은 문자열:%s\n", strstr(a, b));
	system("pause")
	return 0;
}