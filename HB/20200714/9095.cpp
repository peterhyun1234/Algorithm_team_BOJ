// 정수를 1, 2, 3의 합으로 나타내는 방법

#include <iostream>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int t = 0; t < n; t++)
    {
        int inputnum;
        cin >> inputnum;

        int dp[11] = {0};
        dp[1] = 1, dp[2] = 2, dp[3] = 4;

        for (int i = 4; i <= inputnum; i++)
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

        cout << dp[inputnum] << "\n";
    }

    return 0;
}