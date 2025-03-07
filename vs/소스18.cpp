#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void main() {
    char *p;
    char s[81] = "He drinks coke each day.";
    for (p = s + 10; *p != '\0'; p = p + 1) {
        if (*p == 'c')
            *p = 'C';
        if (*p == 'd')
            *p = 'D';
        if (*p == 'e')
            *p = 'E';
        if (*p == ' ')
            *p = '\n';
    }
    printf("%s\n", s);
}