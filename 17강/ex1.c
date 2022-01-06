#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char s[20] = "Hello World";
	FILE *fp;
	fp = fopen("temp.txt", "w");
	fprintf(fp, "%s\n", s);
	fclose(fp);
	return 0;
}