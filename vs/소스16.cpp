#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(){
	int c;
	c=getchar();

	if ((65 <= c) && (c <= 90)) {
		c = c + 32;
		printf("%c", c);
	}

	else if ((97 <= c) && (c <= 122)) {
		c = c - 32;
		printf("%c", c);
	}

	else {
		printf("이거 아니다");
	}
}