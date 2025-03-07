#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* Read() {
	char* name = (char*)malloc(sizeof(char) * 30);
	printf("이름이 뭡니까?: ");
	if (fgets(name, 30, stdin)) {
		name[strcspn(name, "\n")] = '\0';
	}
	return name;
}

int main() {
	char* name1;
	char* name2;
	name1 = Read();
	printf("name1: %s\n", name1);
	name2 = Read();
	printf("name2: %s\n", name2);

	printf("again name1: %s \n", name1);
	printf("again name2: %s \n", name2);

	free(name1);
	free(name2);
	return 0;
}

