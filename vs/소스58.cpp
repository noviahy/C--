#include <iostream>
#include <cstring>  // 문자열 처리를 위해 필요

namespace Full {
    int ID = 0;
    char name[10] = { 0 };  // 배열 초기화
    int total = 0;
}

void Make() {
    std::cout << "정보를 입력하세요" << std::endl;

    std::cout << "계좌ID: ";
    std::cin >> Full::ID;

    std::cout << "이 름: ";
    std::cin >> Full::name;

    std::cout << "잔 액: ";
    std::cin >> Full::total;
}

void Add() {
    int id;
    int k;

    std::cout << std::endl << "[ 입 금 ]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;

    if (id == Full::ID) {  // ID 확인
        std::cout << "입금액: ";
        std::cin >> k;
        Full::total += k;
        std::cout << "입금완료" << std::endl;
    }
    else {
        std::cout << "잘못된 계좌ID입니다." << std::endl;
    }
}

void Sub() {
    int id;
    int k;

    std::cout << "[ 출 금 ]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;

    if (id == Full::ID) {  // ID 확인
        std::cout << "출금액: ";
        std::cin >> k;

        if (Full::total >= k) {
            Full::total -= k;
            std::cout << "출금완료" << std::endl;
        }
        else {
            std::cout << "잔액이 부족합니다" << std::endl;
        }
    }
    else {
        std::cout << "잘못된 계좌ID입니다." << std::endl;
    }
}

void Info() {
    std::cout << "계좌ID: " << Full::ID << std::endl;
    std::cout << "이 름: " << Full::name << std::endl;
    std::cout << "잔 액: " << Full::total << std::endl;
}

int main() {
    int i = 0;  // 변수 초기화

    while (i != 5) {
        std::cout << "--메뉴--" << std::endl;
        std::cout << "1. 계좌개설" << std::endl;
        std::cout << "2. 입금" << std::endl;
        std::cout << "3. 출금" << std::endl;
        std::cout << "4. 계좌정보 전체 출력" << std::endl;
        std::cout << "5. 프로그램 종료" << std::endl;

        std::cout << "선택: ";
        std::cin >> i;

        switch (i) {
        case 1:
            Make();
            break;
        case 2:
            Add();
            break;
        case 3:
            Sub();
            break;
        case 4:
            Info();
            break;
        case 5:
            std::cout << "프로그램을 종료합니다." << std::endl;
            break;
        default:
            std::cout << "잘못된 선택입니다." << std::endl;
            break;
        }
    }

    return 0;
}