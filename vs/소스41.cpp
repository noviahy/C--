#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* src = fopen("C:\\practice\\src.txt", "rb");
	FILE* des = fopen("C:\\practice\\dst.txt", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	while (1) {
		readCnt = fread((void*)buf, 1, sizeof(buf), src);

		if (readCnt < sizeof(buf)) {
			if (feof(src) != 0) {
				fwrite((void*)buf, 1, readCnt, des);
				puts("파일복사 완료");
				break;
			}
			else
				puts("파일복사 실패");

			break;
		}
	}
}