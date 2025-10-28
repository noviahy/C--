// 백준 9251번
// LCS
// C++

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm> // max 해더파일
using namespace std;

class LCS
{
private:
    vector<vector<int>> dp; // DP 테이블
    string lcs1, lcs2;      // 비교할 문자열
    int n;                  // lcs1의 길이
    int m;                  // lsc2의 길이

public:
    // 생성자: 문자열 초기화 및 DP 테이블 준비
    LCS(string str1, string str2)
        : lcs1(str1), lcs2(str2)
    {
        n = str1.length(); // 길이 함수
        m = str2.length();
        this->dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0)); // vector 초기화
    }

    // LCS 계산
    void DoLCS()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (lcs1[i - 1] == lcs2[j - 1]) // 문자가 같으면
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                else                                            // 문자가 다르면
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // max함수 사용으로 더 큰 값 선택
            }
        }
    }

    // 결과 출력
    void PrintResult() 
    {
        cout << dp[n][m] << endl;
    }
};

// 입력 문자열 받기
string InputString() 
{
    string str;

    cin >> str;
    return str;
}

int main()
{
    string str1;
    string str2;

    str1 = InputString();
    str2 = InputString();
    LCS lsc(str1, str2);
    lsc.DoLCS();
    lsc.PrintResult();

    return 0;
}