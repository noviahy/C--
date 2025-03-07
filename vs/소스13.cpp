#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	char s1[]="hello";
	char s2[]="world";
	char s[100];
	int i = 0, j = 0;
	while (s1[i] != 0)
	{
		s[i] = s1[i];
		printf("%d\n", i);
		i++;
	}
	while (s2[j] != 0)
	{
		s[i + j] = s2[j];
		printf("%d %d %d\n", i, j, i + j);
		j++;
	}
	s[i + j] = 0;
	printf("%s\n");
}