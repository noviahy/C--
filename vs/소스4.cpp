#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int i, a, sum;
	printf("\n Enter positive integer number : ");

		scanf("%d", &i);
		sum = 0;
	for (i = i; i >= 0; i = i - 1)
	{	

		do
		{
			if (i % 5 == 0) break;

			else
			{
				sum = sum + i;
				break;
			}
		} while (1);
	}
	printf("\n The sum is %d", sum);
}