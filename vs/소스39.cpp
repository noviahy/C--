#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void arr(char* str) {
	// ���ڿ� ���� ���� ���ڸ� ã�� �� ���� ���ڷ� ��ü
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}
}

void main() {
	char str1[20];
	char str2[20];
	char str3[20];
	int len;

	fgets(str1, sizeof(str1), stdin);
	arr(str1);

	fgets(str2, sizeof(str2), stdin);
	arr(str2);

	strcpy(str3, str1);
	strcat(str3, str2);

	printf("%s", str3);
}