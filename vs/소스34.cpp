#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	char str[7];
	fgets(str, sizeof(str), stdin);
	puts(str);
}