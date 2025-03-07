#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char* strchr1(char *s, char c) {
    int k = 0;
    while (*s != c) {
        s++;
        if (*s == NULL)
            return NULL; // 반환값을 명시적으로 캐스트하지 않고 반환
    }
    return s;
}
