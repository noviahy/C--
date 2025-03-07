#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer[3]; // 컴퓨터가 선택한 숫자 배열
    int guess[3];  // 사용자가 입력한 숫자 배열
    int strikes, balls;
    int attempt = 1;
    int i, j;

    srand((unsigned int)time(NULL));

    // 컴퓨터가 선택한 숫자 초기화 (1부터 9까지의 랜덤한 숫자)
    for (i = 0; i < 3; ++i) {
        answer[i] = 1 + rand() % 9;
    }

    printf("1부터 9까지의 숫자 중에서 숫자 3개를 입력하세요.\n");

    // 3번의 시도
    while (attempt <= 7) {
        printf("\n%d번째 시도\n", attempt);

        // 사용자 입력 받기
        printf("숫자를 입력하세요 (예: 1 2 3): ");
        scanf("%d %d %d", &guess[0], &guess[1], &guess[2]);

        // 초기화
        strikes = 0;
        balls = 0;

        // strike와 ball 계산
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

        // 결과 출력
        printf("스트라이크: %d, 볼: %d\n", strikes, balls);

        // 맞췄는지 확인
        if (strikes == 3) {
            printf("축하합니다! 숫자를 모두 맞추셨습니다.\n");
            break;
        }


        // 다음 시도로 넘어감
        attempt++;
    }

    // 모든 시도 후에 정답 출력
    printf("\n정답은 ");
    for (i = 0; i < 3; ++i) {
        printf("%d ", answer[i]);
    }
    printf("입니다.\n");

    return 0;
}
