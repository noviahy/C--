#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_arr(int arr[], int len);
int max_diff(int arr[], int len);

int main() {

    int value[10] = { 1, 2, 3, 4, 12, 24, 48, 8, 9, 10 };
    print_arr(value, 10);

    int difference = max_diff(value, 10);
    printf("\n%d = maximum difference", difference);
}


void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int max_diff(int arr[], int len) {
    if (len == 1) {
        return 0;
    }

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return max - min;
}