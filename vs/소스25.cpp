#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10
void copy1(char s1[], char s2[]);
void copy2(char* s1, char* s2);

void main() {
	char string1[SIZE] = { 0, };
	char* string2 = "Hello";
	char string3[SIZE] = { 0, };
	char string4[] = "Good Bye";

	copy1(string1, string2);
	printf("string1=%s\n", string1);

	copy2(string3, string4);
	printf("string3=%s\n", string3);
}

void copy1(char s1[], char s2[]) {
	for (int i = 0; s2[i] != NULL; i++)
		s1[i] = s2[i];
}

void copy2(char* s1, char* s2) {
	while (*s2 != NULL)
		*s1++ = *s2++;
	for (*s1 = *s2; *s2 != NULL; s1++, s2++)
		*s1 = *s2;
}