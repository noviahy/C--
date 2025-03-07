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

    srand((unsigned int)time(NULL)); // 난수 발생기 초기화

    while (round <= 3) {
        // 사용자에게 입력 받기
        printf("가위(1), 바위(2), 보(3) 중 하나를 선택하세요: ");
        scanf("%d", &playerChoice);

        // 컴퓨터의 선택 (1부터 3 사이의 랜덤 값)
        computerChoice = 1 + rand() % 3;

        // 결과 출력
        printf("Round %d:\n", round);
        printf("사용자 선택: %d\n", playerChoice);
        printf("컴퓨터 선택: %d\n", computerChoice);

        // 게임 결과 계산
        if (playerChoice == computerChoice) {
            printf("무승부!\n");
            draws++;
        }
        else if ((playerChoice == 1 && computerChoice == 3) ||
            (playerChoice == 2 && computerChoice == 1) ||
            (playerChoice == 3 && computerChoice == 2)) {
            printf("사용자 승!\n");
            playerWins++;
        }
        else {
            printf("컴퓨터 승!\n");
            computerWins++;
        }

        round++;
    }

    // 최종 결과 출력
    printf("\n게임 종료!\n");
    printf("총 결과:\n");
    printf("사용자 승수: %d\n", playerWins);
    printf("컴퓨터 승수: %d\n", computerWins);
    printf("무승부 수: %d\n", draws);

    return 0;
}
