#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	char message[81];
	char c;
	int i, k;

	printf("enter a string : \n");
	i = 0;
	while (1)
	{
		c = getchar();
		if (c == '\n' || i == 80)
			break;
		message[i] = c;
		i = i + 1;
	}
	message[i] = '\0';
	k = 0;
	while (k <= i)
	{
		putchar(message[k]);
		k += 1;
	}
	printf("The string you entered is: %s\n", message[i]);
}