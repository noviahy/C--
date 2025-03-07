#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;


int main() {
	char arr1[100];
	char arr2[100];

	cin >> arr1;
	cin >> arr2;

	strcat(arr1, arr2);
	
	cout << strlen(arr1) << endl;

	strcpy(arr2, arr1);

	if (strcmp(arr1, arr2)==0)
		cout << "같다";

	else
		cout << "다르다";


	return 0;
}