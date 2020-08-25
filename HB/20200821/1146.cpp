// N명의 학생들이 있다. 이 학생들을 다음과 같은 방식으로 줄을 세우려고 한다.

// 1. 맨 앞줄에는 아무나 설 수 있다.

// 2. 둘째 줄에도 아무나 설 수 있다.

// 3. 셋째 줄에는
// 3.1. 둘째 줄 > 첫째 줄 => 둘째 줄보다 작은 사람만이 설
// 3.2. 둘째 줄 < 첫째 줄 => 둘째 줄보다 큰 사람만이 설

// 4. 넷째 줄부터는 N번째의 줄을 서는 사람은 N-2번째 줄과 N-1번째 줄에 서는 사람을 비교

// 학생들이 1이 가장 작은 사람, N이 가장 큰 사람

// 5명을 세운다면 (크작 크작 번갈아가면서)
// 1 - 3 - 2 - 5 - 4
// 3 - 2 - 5 - 1 - 4

// N명의 학생을 이런 식으로 줄을 세울 때 총 몇 가지의 경우의 수

// 시간은 ㄱㅊㄱㅊ
// 첫째 줄에 총 경우의 수를 1,000,000으로 나눈 나머지를 출력

// DP로 푸는 문제 ㄱㄱ
// 이건 내가 외우지 않는 한 절대 절대 못품

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000;
int n, dp[100][100][100][2];

int solve(int here, int left, int right, bool makeRight)
{
    if (here == n)
        return 1;
    int &ret = dp[here][left][right][makeRight];
    if (ret != -1)
        return ret;

    ret = 0;
    if (makeRight) // 오른쪽으로 진행되는 경우
    {
        if (right == 0)
            return ret;
        for (int i = 0; i < right; ++i)
            ret = (ret + solve(here + 1, left + i, right - 1 - i, !makeRight)) % MOD;
    }
    else
    {
        if (left == 0)
            return ret;
        for (int i = 0; i < left; ++i)
            ret = (ret + solve(here + 1, left - 1 - i, right + i, !makeRight)) % MOD;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = (ans + solve(1, i, n - i - 1, true)) % MOD;
        ans = (ans + solve(1, i, n - i - 1, false)) % MOD;
    }
    cout << ans;
}