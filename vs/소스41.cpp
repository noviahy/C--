#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	FILE* src = fopen("C:\\practice\\src.txt", "rb");
	FILE* des = fopen("C:\\practice\\dst.txt", "wb");
	char buf[20];
	int readCnt;

	if (src == NULL || des == NULL) {
		puts("���Ͽ��� ����!");
		return -1;
	}

	while (1) {
		readCnt = fread((void*)buf, 1, sizeof(buf), src);

		if (readCnt < sizeof(buf)) {
			if (feof(src) != 0) {
				fwrite((void*)buf, 1, readCnt, des);
				puts("���Ϻ��� �Ϸ�");
				break;
			}
			else
				puts("���Ϻ��� ����");

			break;
		}
	}
}