#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* strchr1(char *s, char c) {
    int k = 0;
    while (*s != c) {
        s++;
        if (*s == NULL)
            return NULL; // ��ȯ���� ��������� ĳ��Ʈ���� �ʰ� ��ȯ
    }
    return s;
}
