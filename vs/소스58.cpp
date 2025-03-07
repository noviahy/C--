#include <iostream>
#include <cstring>  // ���ڿ� ó���� ���� �ʿ�

namespace Full {
    int ID = 0;
    char name[10] = { 0 };  // �迭 �ʱ�ȭ
    int total = 0;
}

void Make() {
    std::cout << "������ �Է��ϼ���" << std::endl;

    std::cout << "����ID: ";
    std::cin >> Full::ID;

    std::cout << "�� ��: ";
    std::cin >> Full::name;

    std::cout << "�� ��: ";
    std::cin >> Full::total;
}

void Add() {
    int id;
    int k;

    std::cout << std::endl << "[ �� �� ]" << std::endl;
    std::cout << "����ID: ";
    std::cin >> id;

    if (id == Full::ID) {  // ID Ȯ��
        std::cout << "�Աݾ�: ";
        std::cin >> k;
        Full::total += k;
        std::cout << "�ԱݿϷ�" << std::endl;
    }
    else {
        std::cout << "�߸��� ����ID�Դϴ�." << std::endl;
    }
}

void Sub() {
    int id;
    int k;

    std::cout << "[ �� �� ]" << std::endl;
    std::cout << "����ID: ";
    std::cin >> id;

    if (id == Full::ID) {  // ID Ȯ��
        std::cout << "��ݾ�: ";
        std::cin >> k;

        if (Full::total >= k) {
            Full::total -= k;
            std::cout << "��ݿϷ�" << std::endl;
        }
        else {
            std::cout << "�ܾ��� �����մϴ�" << std::endl;
        }
    }
    else {
        std::cout << "�߸��� ����ID�Դϴ�." << std::endl;
    }
}

void Info() {
    std::cout << "����ID: " << Full::ID << std::endl;
    std::cout << "�� ��: " << Full::name << std::endl;
    std::cout << "�� ��: " << Full::total << std::endl;
}

int main() {
    int i = 0;  // ���� �ʱ�ȭ

    while (i != 5) {
        std::cout << "--�޴�--" << std::endl;
        std::cout << "1. ���°���" << std::endl;
        std::cout << "2. �Ա�" << std::endl;
        std::cout << "3. ���" << std::endl;
        std::cout << "4. �������� ��ü ���" << std::endl;
        std::cout << "5. ���α׷� ����" << std::endl;

        std::cout << "����: ";
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
            std::cout << "���α׷��� �����մϴ�." << std::endl;
            break;
        default:
            std::cout << "�߸��� �����Դϴ�." << std::endl;
            break;
        }
    }

    return 0;
}