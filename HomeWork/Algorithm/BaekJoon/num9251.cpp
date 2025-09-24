// 백준 9251번
// LCS
// C++

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class LCS
{
private:
    vector<vector<int>> dp;
    string lcs1;
    string lcs2;
    int n;
    int m;

public:
    LCS(string str1, string str2)
        : lcs1(str1), lcs2(str2)
    {
        n = str1.length();
        m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    }

    void DoLCS()
    {
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; i++)
            {
                if (lcs1[i - 1] == lcs2[j - 1])
                {
                }

                else
                {
                    if
                }
            }
        }
    }

    void PrintResult()
    {
        cout << dp[n][m] << endl;
    }
};

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

    return 0;
}