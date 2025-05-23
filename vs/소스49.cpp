#include <iostream>

void Swap(int* ref1, int* ref2) {
	int temp = *ref1;
	*ref1 = *ref2;
	*ref2 = temp;
}

void main() {
	int val1 = 10;
	int val2 = 20;

	std::cout << "val1: " << val1 << std::endl;
	std::cout << "val2: " << val2 << std::endl;

	Swap(&val1, &val2);

	std::cout << "val1: " << val1 << std::endl;
	std::cout << "val2: " << val2 << std::endl;
}