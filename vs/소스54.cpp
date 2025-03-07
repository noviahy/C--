#include <iostream>

int main() {

	std::cout << "이름, 전화번호를 임력하세요";


	char arr1[6];
	char arr2[20];
	std::cin >> arr1>>arr2;

	std::cout << "이름: "<<arr1<<std::endl;
	std::cout << "번호: " << arr2;
}