#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void main()
{
	int total, k;
	float avg;
	total = 0;
	for (k = 1; k < 11; k = k + 1)
	{
		total = total + k;
		printf("k=%d and result =%d", k, total);
	}
	avg = total / 10.0;
}