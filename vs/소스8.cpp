#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define RESP_SIZE 10
#define FREQ_SIZE 9

int main() {
    int response[RESP_SIZE] = { 1, 3, 4, 5, 2, 3, 5, 4, 8, 9 };
    int frequency[FREQ_SIZE] = { 0 };

    for (int i = 0; i < RESP_SIZE; i++) {
        if (response[i] >= 1 && response[i] <= FREQ_SIZE) {
            frequency[response[i] - 1]++;
        }
    }
    for (int i = 0; i < FREQ_SIZE; i++) {
        printf("%d %d\n", i + 1, frequency[i]);
    }
}