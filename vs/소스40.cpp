#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void main() {
    char str1[20];
    char str2[20];
    char str3[20];
    int len;

    // ù ��° ���ڿ� �Է� �ޱ�
    fgets(str1, sizeof(str1), stdin);
    len = sizeof(str1) / sizeof(str1[0]);
    if (len > 0 && str1[len - 1] == '\n')
        str1[len - 1] = '\0'; // ���� ���� ����

    // �� ��° ���ڿ� �Է� �ޱ�
    fgets(str2, sizeof(str2), stdin);
    len = sizeof(str2) / sizeof(str2[0]);
    if (len > 0 && str2[len - 1] == '\n')
        str2[len - 1] = '\0'; // ���� ���� ����

    // str1�� str3�� ����
    strcpy(str3, str1);

    // str2�� str3�� �̾���̱�
    strcat(str3, str2);

    // ��� ���
    printf("%s", str3);
}
