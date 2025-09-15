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
    vector<vector<int>> arr; // vector 사용 - 범위 초기화 미룸

public:
    Quard(int i) // 생성자
        : binary(i)
    {
        CreateArr(binary);
    }

    void CreateArr(int binary) // 어레이 생성
    {
        arr.resize(binary, vector<int>(binary, 0));
        InputArr(); // 어레이에 값 넣음
    }

    void InputArr() // 배열 값 넣기
    {
        for (int i = 0; i < binary; i++)
        {
            string s;
            cin >> s; // 한 줄 전체 읽기
            for (int j = 0; j < binary; j++)
            {
                arr[i][j] = s[j] - '0'; // 문자 -> 숫자 변환
            }
        }
        DoQuard(binary, 0, 0); // Quard 실행
    }

    int Check(int num, int row, int column)
    {
        int first = arr[row][column]; // 첫번째 값을 기준으로 다음값 비교
        for (int i = 0; i < num; i++) // 행
        {
            for (int j = 0; j < num; j++) // 열
            {
                if (arr[row + i][column + j] != first) // 값이 다를때
                {
                    return -1; // -1 반환
                }
            }
        }
        return first; // 값이 같을때 first값 반환
    }

    void DoQuard(int num, int row, int column) // 이진수값을 받음
    {
        int result = Check(num, row, column); // -1값 또는 first값
        if (result != -1)
        {
            cout << result; // 반환값 출력
            return;         // 출력 후 DoQuard 종료
        }

        int half = num / 2;

        cout << '(';
        DoQuard(half, row, column);               // 좌상단
        DoQuard(half, row, column + half);        // 우상단
        DoQuard(half, row + half, column);        // 좌하단
        DoQuard(half, row + half, column + half); // 우하단
        cout << ')';
    }
};

int InputBin() // 2진수 입력 범위 외 반복
{
    int binary = 0;
    cin >> binary;
    return binary; // 2진수 반환
}

int main() // 메인함수
{
    int i = InputBin();
    Quard tree(i); // arr에 0 혹은 1입력 + Quary 진행

    return 0;
}