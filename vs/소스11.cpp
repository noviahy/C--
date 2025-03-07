#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char message[] = "I Love C Programming.";
	printf("%s", message);
	printf("%25s \n%25.4s\n", message, message);
	puts(message);
}