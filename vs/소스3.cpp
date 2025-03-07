#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int i, a, total;

	printf("\n Enter a 5 - digit number: ");
	do
	{
		scanf("%d", &i);

		if((i<0) && (i>9999))
			continue;
		else
			break;
	} while (1);

		if (i / 9000 == 1)
		{
			total = total + 1;
		}
		if ((i % 1000) / 900 == 1)
		{
			total = total + 1;
		}
		if (((i % 1000) % 100) / 90 == 1)
		{
			total = total + 1;
		}
		if ((((i % 1000) % 100) % 10) / 9 == 1)
		{
			total = total + 1;
		}
	else
	{
		total == 0;
	}
	printf("The number %d has total %d nines(s) in it", i,total);
}