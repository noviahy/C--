#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void RemoveBSN(char str[]) {
	int len = strlen(str);
	str[len - 1]=0;
}

int main() {
	char str[100];
	printf("문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	printf("길이: %d, 내용: %s \n", strlen(str), str);

	RemoveBSN(str);
	printf("길이: %d, 내용 %s \n", strlen(str), str);
	return 0;
}