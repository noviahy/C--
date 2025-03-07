#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void calculate(int, int, int*, int*, int*, int*);
void main() {
	int n1, n2;
	int res1, res2, res3, res4;
	printf("n1,n2: ");
	scanf("%d %d", &n1, &n2);
	calculate(n1, n2, &res1, &res2, &res3, &res4);
	printf("N1*N2: %d\n", res1);
	printf("N1/N2: %d\n", res2);
	printf("N1%%N2: %d\n", res3);
	printf("N1+N2: %d\n", res4);
}
void calculate(int n1, int n2, int* re1, int* re2, int* re3, int* re4) {
	*re1 = n1 * n2;
	*re2 = n1 / n2;
	*re3 = n1 % n2;
	*re4 = n1 + n2;
}