#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_prime(int n) {
    if (n <= 1) return 0;  // 1과 1 미만의 수는 소수가 아님
    if (n <= 3) return 1;  // 2와 3은 소수

    // 2와 3을 제외한 수 중에서 2 또는 3으로 나누어 떨어지는지 확인
    if (n % 2 == 0 || n % 3 == 0) return 0;

    // 나머지 소수는 6k ± 1 형태를 가지는 것으로 알려져 있음
    // 6k ± 1 형태의 수로만 나누어 떨어지는지 확인
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }

    return 1;
}

void factorize(int n) {
    printf("The prime factors of %d are: ", n);

    int isFirstFactor = 1;
    while (n > 1) {
        for (int i = 2; i <= n; i++) {
            if (is_prime(i) && n % i == 0) {
                if (!isFirstFactor) {
                    printf(" * ");
                }
                printf("%d", i);
                n /= i;
                isFirstFactor = 0;
                break;
            }
        }
    }

    printf("\n");
}

int main() {
    float input;

    printf("Enter a number: ");
    scanf("%f", &input);

    if ((int)input != input) {
        printf("%.2f is a non-integer number\n", input);
    }
    else {
        if (input == 1) {
            printf("%.2f is one\n", input);
        }
        else if (input < 0) {
            printf("%.2f is a negative number\n", input);
        }
        else if (is_prime((int)input)) {
            printf("%.2f is a prime number\n", input);
        }
        else {
            printf("%.2f is not a prime number. ", input);
            printf("The prime factors of %.2f are: ", input);
            factorize((int)input);
            printf("It is also a composite number.\n");
        }
    }

    return 0;
}

