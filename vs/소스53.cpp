#include <iostream>

int main() {
	int arr[5];
	int total = 0;

	for (int i = 1; i < 6; i++)
	{
		std::cout << i << "��° ���� �Է�: ";
		std::cin >> arr[i];
	}
	
	for (int i = 1; i < 6; i++)
	{
		total += arr[i];
	}

	std::cout << "�հ�: " << total;
}