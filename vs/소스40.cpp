#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main() {
    char str1[20];
    char str2[20];
    char str3[20];
    int len;

    // 첫 번째 문자열 입력 받기
    fgets(str1, sizeof(str1), stdin);
    len = sizeof(str1) / sizeof(str1[0]);
    if (len > 0 && str1[len - 1] == '\n')
        str1[len - 1] = '\0'; // 개행 문자 제거

    // 두 번째 문자열 입력 받기
    fgets(str2, sizeof(str2), stdin);
    len = sizeof(str2) / sizeof(str2[0]);
    if (len > 0 && str2[len - 1] == '\n')
        str2[len - 1] = '\0'; // 개행 문자 제거

    // str1을 str3에 복사
    strcpy(str3, str1);

    // str2를 str3에 이어붙이기
    strcat(str3, str2);

    // 결과 출력
    printf("%s", str3);
}
