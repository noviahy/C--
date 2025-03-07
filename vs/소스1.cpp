#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int N1, N2, total;

	printf("\n type N1 \n");
	scanf("%d", &N1);
	printf("\n type N2 \n");
	scanf("%d", &N2);

	if (N1 > 20)
	{
		total = N1 - N2;
		printf("\n N1 = %d N2 = %d total = %d \n", N1, N2, total);
	}
	else if ((10 <= N1) && (N1 <= 20))
	{
		total = N1 + N2;
		printf("\n N1 = %d N2 = %d total = %d \n", N1, N2, total);
	}
	else
	{
		total = N1 * N2;
		printf("\n N1 = %d N2 = %d total = %d \n", N1, N2, total);
	}
}