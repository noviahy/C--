#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer[3]; // ��ǻ�Ͱ� ������ ���� �迭
    int guess[3];  // ����ڰ� �Է��� ���� �迭
    int strikes, balls;
    int attempt = 1;
    int i, j;

    srand((unsigned int)time(NULL));

    // ��ǻ�Ͱ� ������ ���� �ʱ�ȭ (1���� 9������ ������ ����)
    for (i = 0; i < 3; ++i) {
        answer[i] = 1 + rand() % 9;
    }

    printf("1���� 9������ ���� �߿��� ���� 3���� �Է��ϼ���.\n");

    // 3���� �õ�
    while (attempt <= 7) {
        printf("\n%d��° �õ�\n", attempt);

        // ����� �Է� �ޱ�
        printf("���ڸ� �Է��ϼ��� (��: 1 2 3): ");
        scanf("%d %d %d", &guess[0], &guess[1], &guess[2]);

        // �ʱ�ȭ
        strikes = 0;
        balls = 0;

        // strike�� ball ���
        for (i = 0; i < 3; ++i) {
            if (guess[i] == answer[i]) {
                strikes++;
            }
            else {
                for (j = 0; j < 3; ++j) {
                    if (guess[i] == answer[j]) {
                        balls++;
                    }
                }
            }
        }

        // ��� ���
        printf("��Ʈ����ũ: %d, ��: %d\n", strikes, balls);

        // ������� Ȯ��
        if (strikes == 3) {
            printf("�����մϴ�! ���ڸ� ��� ���߼̽��ϴ�.\n");
            break;
        }


        // ���� �õ��� �Ѿ
        attempt++;
    }

    // ��� �õ� �Ŀ� ���� ���
    printf("\n������ ");
    for (i = 0; i < 3; ++i) {
        printf("%d ", answer[i]);
    }
    printf("�Դϴ�.\n");

    return 0;
}
