#include <iostream>

int main() {
	int arr[5];
	int total = 0;

	for (int i = 1; i < 6; i++)
	{
		std::cout << i << "번째 정수 입력: ";
		std::cin >> arr[i];
	}
	
	for (int i = 1; i < 6; i++)
	{
		total += arr[i];
	}

	std::cout << "합계: " << total;
}