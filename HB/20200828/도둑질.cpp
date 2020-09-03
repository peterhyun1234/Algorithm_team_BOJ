#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money)
{
    int answer = 0;
    int n = money.size();
    vector<vector<int>> dp(2, vector<int>(n));

    dp[0][0] = money[0];
    dp[0][1] = money[0];
    for (int i = 2; i < n - 1; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[0][i - 2] + money[i]);
    }

    dp[1][0] = 0;
    dp[1][1] = money[1];
    for (int i = 2; i < n; i++)
    {
        dp[1][i] = max(dp[1][i - 1], dp[1][i - 2] + money[i]);
    }

    answer = max(dp[0][n - 2], dp[1][n - 1]);

    return answer;
}
