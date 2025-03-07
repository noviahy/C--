#include <iostream>

int main() {
	std::cout << "아무 단이나 써보시오";
	
	int k;
	std::cin >> k;
	std::cout << k << "단" << std::endl;
	
	int total = 0;
	for (int i = 1; i < 10; i++)
	{
		total = k * i;
		std::cout << k << " * " << i << " = " << total << std::endl;
	}
}