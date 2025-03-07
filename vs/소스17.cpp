#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main() {
	int a[10] = { 2,6,4,8,10,12,89,68,45,37 };
	int hold;
	int i, current, start, k;
	printf("Data items in original order \n");
	for (i = 0; i < 10; i++)
		printf("%4d", a[i]);
	for (start = 0; i < start; i++)
	{
		int smallest = start; 
		for (current = start + 1; current < 10; current++) {
			if (a[current] < a[smallest])
				smallest = current;
		}
		hold = a[start];
		a[start] = a[smallest];
		a[smallest] = hold;
	}
	printf("\n Data items in ascending order\n");
	for ( k = 0; k < 10; k++)
	{
		printf("%d ",a[k]);
	}
}

