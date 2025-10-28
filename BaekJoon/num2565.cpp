// 백준 2565번
// 전깃줄
// C++

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm> // max 해더파일
using namespace std;

class LIS
{
private:
    vector<int> dp; // DP 테이블
    int num;        // 전기줄 개수
    vector<int> A;  // 왼쪽 전봇대 번호
    vector<int> B;  // 오른쪽 전봇대 번호

public:
    // 생성자: 전기줄 개수 초기화, 백터/dp 준비
    LIS(int num)
        : num(num)
    {
        this->dp = vector<int>(num, 1); // dp 초기값 1
        this->A = vector<int>(num);
        this->B = vector<int>(num);
    }

    // 전기줄 정보 입력
    void InputArr()
    {
        for (int i = 0; i < num; i++)
            cin >> A[i] >> B[i];
    }

    // A 전봇대 기준으로 전깃줄 정렬 (B도 함꼐 이동)
    void DoSort()
    {
        vector<pair<int, int>> wires(num);
        for (int i = 0; i < num; i++)
            wires[i] = {A[i], B[i]};

        sort(wires.begin(), wires.end()); // A 기준 오름차순

        for (int i = 0; i < num; i++)
        {
            A[i] = wires[i].first;
            B[i] = wires[i].second;
        }
    }

    // LIS 계산
    void DoLIS()
    {
        for (int i = 1; i < num; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (B[i] > B[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 결과 출력: 제거해야 할 전깃줄 수
    void PrintResult()
    {
        cout << num - *max_element(dp.begin(), dp.end()) << endl;
    }
};

// 전깃줄 개수 입력
int InputNum()
{
    int num;
    cin >> num;
    return num;
}

int main()
{
    int num;
    num = InputNum();

    LIS lis(num);
    lis.InputArr();
    lis.DoSort();
    lis.DoLIS();
    lis.PrintResult();

    return 0;
}