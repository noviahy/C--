#include <iostream>
using namespace std;

int& RefRet(int& ref) {
	ref++;
	return ref;
}

int main() {
	int num1 = 1;
	int num2 = RefRet(num1);

	num1++;
	num2++;
	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}