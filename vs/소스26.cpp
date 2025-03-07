#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int num = 45, * ptr, ** ptr2ptr;
	ptr = &num;
	ptr2ptr = &ptr;
	printf("%d", **ptr2ptr);
}