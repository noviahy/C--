#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	char message[100];
	int i = 0;

	printf("Enter a string\n");

	while (i < 99 && message[i] != '\n')
	{
		++i; 
		scanf("%c", &message[i]);
	}
	message[i] = '\0';

	for (i = i - 1; i > 0; --i)
	{
		printf("%c", message[i]);
	}
}
