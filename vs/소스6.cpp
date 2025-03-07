#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int i, a;
	printf("Enter the size of triangle : ");
	scanf("%d", &a);

	for (a = a; a >= 0; a = a - 1)
	{
		for (i = a; i >= 0; i = i - 1)
		{
			printf("*");
		}
		printf("\n");
	}
}