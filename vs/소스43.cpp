#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(){
	double num = 3.14;
	double* ptr = &num;
	double** dptr = &ptr;
	double* ptr2;

	printf("%9p %9p \n", ptr, *dptr);
	printf("%9g % 9g \n", num, **dptr);
	ptr2 = *dptr;
	*ptr2 = 10.99;
	printf("%9g %9g \n", num, **dptr);
}