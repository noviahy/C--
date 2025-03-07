#include <iostream>
using namespace std;

int& RefRet(int& ref) {
	ref++;
	return ref;
}

void main() {
	int num1 = 1;
	int num2 = RefRet(num1);

	num1 += 1;
	num2 += 100;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}