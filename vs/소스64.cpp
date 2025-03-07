#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void main()
{
	int num1, num2, num3;

	printf("\n please type an integer: \n");
	scanf("%d", &num1);
	printf("\n please type another integer: \n");
	scanf("%d", &num2);

	num3 = num1 + num2;
	printf("result=%d", num3);
}