#include <iostream>

int main() {
	std::cout << "�ƹ� ���̳� �Ẹ�ÿ�";
	
	int k;
	std::cin >> k;
	std::cout << k << "��" << std::endl;
	
	int total = 0;
	for (int i = 1; i < 10; i++)
	{
		total = k * i;
		std::cout << k << " * " << i << " = " << total << std::endl;
	}
}