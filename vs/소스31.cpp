#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print(int arr[4][4]) {
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void turn(int arr[4][4]) {
	int arr1[4][4];
	int i, j;

	for (int k = 0; k < 4; k++) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				arr1[j][3 - i] = arr[i][j];
			}
		}

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				arr[i][j] = arr1[i][j];
			}
		}
		print(arr);
	}
}

void main(){
	int  arr[4][4] =
	{ 1,2,3,4,
	  5,6,7,8,
	  9,10,11,12,
	  13,14,15,16 };

	print(arr);
	turn(arr);
}
