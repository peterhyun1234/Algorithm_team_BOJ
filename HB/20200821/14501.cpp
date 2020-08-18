// 최대한 많은 상담

// 첫째 줄에 N (1 ≤ N ≤ 15)
// 둘째 줄부터 N개의 줄에 Ti와 Pi가 공백으로

// 백준이가 얻을 수 있는 최대 이익

// DP로 푸는 문제!

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> schedules(51);
    vector<int> dp(51);

    for (int i = 1; i <= n; i++){
        cin >> schedules[i].first >> schedules[i].second;
    }

    int max_profit = 0;

    for (int i = 1; i <= n; i++)
    {
        int performing_counseling = i + schedules[i].first;
        if (performing_counseling <= n + 1){
            dp[performing_counseling] = max(dp[performing_counseling], dp[i] + schedules[i].second);
        }

        int not_performing_counseling = i + 1;
        if (not_performing_counseling <= n + 1){
            dp[not_performing_counseling] = max(dp[not_performing_counseling], dp[i]);
        }

        max_profit = max(max(max_profit, dp[performing_counseling]), dp[not_performing_counseling]);
    }

    cout << max_profit << "\n";

    return 0;
}
