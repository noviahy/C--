#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	char str[7];
	int i;

	for (i = 0; i < 3; i++)
	{
		fgets(str, 5, stdin);
		printf("Read %d: %s \n", i + 1, str);
	}
}