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
    int binary; // 영상의 크기 
    vector<vector<int>> arr; // 입력 영상 저장

public:
    Quard(int i) // 생성자:: 크기를 입력받아 배열 생성
        : binary(i)
    {
        CreateArr(binary);
    }

    void CreateArr(int binary) //영상 크기에 맞는 배열 생성
    {
        arr.resize(binary, vector<int>(binary, 0));
        InputArr(); // 배열에 입력값 저장
    }

    void InputArr() // 배열 값 입력
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
        DoQuard(binary, 0, 0); // 쿼드트리 분할 시작
    }

    int Check(int num, int row, int column)
    {
        // 현재 영역의 첫 번째 값을 기준으로 전체 검사
        int first = arr[row][column];
        for (int i = 0; i < num; i++) // 행
        {
            for (int j = 0; j < num; j++) // 열
            {
                if (arr[row + i][column + j] != first) // 하나라도 값이 다르면
                {
                    return -1; // -1 반환
                }
            }
        }
        return first; // 값이 전부 같을때 first값 반환
    }

    void DoQuard(int num, int row, int column) // 이진수값을 받음
    {
        // 현재 영역이 모두 같은 값인지 확인
        int result = Check(num, row, column);
        if (result != -1) // 모두 같은 경우
        {
            cout << result; // 0 또는 1 출력
            return;         // 더 이상 분할하지 않음
        }

        // 다르면 4등분하여 재귀 처리
        int half = num / 2;

        cout << '('; // 분할 시작 표시
        DoQuard(half, row, column);               // 좌상단
        DoQuard(half, row, column + half);        // 우상단
        DoQuard(half, row + half, column);        // 좌하단
        DoQuard(half, row + half, column + half); // 우하단
        cout << ')'; // 분할 종료 표시
    }
};

int InputBin() // 영상 크기 입력
{
    int binary = 0;
    cin >> binary;
    return binary; // 2진수 반환
}

int main()
{
    int i = InputBin(); // 영상 크기 입력
    Quard tree(i); // 객체 생성 -> 입력 + 쿼드트리 압축 실행

    return 0;
}