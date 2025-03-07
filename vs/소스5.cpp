#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int i, sum;
	
	do
	{
		printf("\n Guss correct number : ");
		scanf("%d", &i);
		sum = 1;
		if (i < 59)
		{
			printf("\n your suggested number is too low!");
			sum = sum + 1;
			continue;
		}
		else if (i > 59)
		{
			printf("\n your suggested number is too high!");
			sum = sum + 1;
			continue;
		}

		else if (i == 59)
		{
			printf("\n correct number.congratulation!");
			sum = sum + 1;
			break;
		}
		
	} while (1);
	printf("\n The number of attempts is %d", sum);
}