#include <stdio.h>

int a[2][3][3] ={ { { 1, 2, 3 }, { 4, 5, 6 }, {7, 8, 9} },
									{ { 1, 2, 3 }, { 4, 5, 6 }, {7, 8, 9} } };
int main(void) {
	int i, j, k;
	for (i=0; i<2; i++){
		for (j=0; j<3; j++){
			for (k=0; k<3; k++){
				printf("%d ", a[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}