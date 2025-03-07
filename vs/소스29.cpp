#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main() {
	char* s;
	char buf[81] = "This is a test";
	s = strchr(buf, 't');
	if (s != NULL)
		printf("found a 't' at %p\n", s);
}