// 백준 1992번
// 쿼드트리
// C++

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Quard
{
private:
    int binary;
    vector<vector<int>> arr;

public:
    Quard(int i) // 생성자
        : binary(i)
    {
        CreateArr(binary);
    }

    void CreateArr(int binary) // 어레이 생성
    {
        arr.resize(binary, vector<int>(binary, 0));
        InputArr();
    }

    void InputArr() // 어레이 값 넣기
    {
        int num;
        for (int i = 0; i < binary; i++)
        {
            for (int j = 0; j < binary; j++)
            {
                cin >> num;
                arr[i][j] = num;
            }
            cout << endl;
        }
        DoQuard(binary / 2);
    }

    bool Check(int num, int row, int column)
    {
        int first = arr[row][column];
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (arr[row + i][column + j] != first)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void DoQuard(int num)
    {
        cout << '(';
        int divide = num;



        /*
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (Check(divide, divide * i, divide * j) == true) // 박스가 모두 같지 않을때
                {
                   return DoQuard(divide / 2);
                }
                else // 모두 같을때
                {
                    cout << arr[i * divide][j * divide];
                }
            }
            cout << ')';
        }*/
    }

    void Output(){
        
    }
};

int InputBin() // 2진수 입력 범위 외 반복
{
    int binary = 0;
    cout << "Enter a binary number N (0 < N < 65): ";
    cin >> binary; // 입력받기
    if (binary <= 0 || binary >= 65 || (binary & (binary - 1)) != 0)
    {
        cout << "Not within range. Please input again" << endl;
        return InputBin();
    }
    return binary;
}

int main() // 메인함수
{
    int i = InputBin();
    Quard tree(i);

    return 0;
}