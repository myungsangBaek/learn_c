#include <stdio.h>

void myFuction(){
	printf("It's my fuction.\n");
}

void yourFuction(){
	printf("It's your fuction.\n");
}

int main(void) {
	void(*fp)() = myFunction;
	fp();
	fp = yourFunction;
	fp();
	system("pause");
	return 0;
}
// my
// your