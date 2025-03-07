#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char string1[81], string2[81];
	int i = 0;

	while (string2[i] != '\0')
	{
		string1[i] = string2[2];
		i++;
	}
	string1[i] = '\0';
}