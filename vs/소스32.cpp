#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice;
    int computerChoice;
    int playerWins = 0;
    int computerWins = 0;
    int draws = 0;
    int round = 1;

    srand((unsigned int)time(NULL)); // ���� �߻��� �ʱ�ȭ

    while (round <= 3) {
        // ����ڿ��� �Է� �ޱ�
        printf("����(1), ����(2), ��(3) �� �ϳ��� �����ϼ���: ");
        scanf("%d", &playerChoice);

        // ��ǻ���� ���� (1���� 3 ������ ���� ��)
        computerChoice = 1 + rand() % 3;

        // ��� ���
        printf("Round %d:\n", round);
        printf("����� ����: %d\n", playerChoice);
        printf("��ǻ�� ����: %d\n", computerChoice);

        // ���� ��� ���
        if (playerChoice == computerChoice) {
            printf("���º�!\n");
            draws++;
        }
        else if ((playerChoice == 1 && computerChoice == 3) ||
            (playerChoice == 2 && computerChoice == 1) ||
            (playerChoice == 3 && computerChoice == 2)) {
            printf("����� ��!\n");
            playerWins++;
        }
        else {
            printf("��ǻ�� ��!\n");
            computerWins++;
        }

        round++;
    }

    // ���� ��� ���
    printf("\n���� ����!\n");
    printf("�� ���:\n");
    printf("����� �¼�: %d\n", playerWins);
    printf("��ǻ�� �¼�: %d\n", computerWins);
    printf("���º� ��: %d\n", draws);

    return 0;
}
