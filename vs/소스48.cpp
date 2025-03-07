#include <iostream>

void Add(int& k) {
	k = k + 1;
}

void Tt(int& h) {
	h = h * -1;
}


void main() {
	int num;
	std::cin >> num;
	Add(num);
	std::cout << num << std::endl;
	Tt(num);
	std::cout << num << std::endl;
}
