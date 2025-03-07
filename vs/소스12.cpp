#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char message[100];
	int i;
	i = 0;

	printf("enter a string:\n");
	gets_s(message);

	while (message[i] != '\0')
	{
		i = i + 1;
	}
	printf("number of characters : % d\n", i);
}