// 계단은 한 번에 한 계단씩 또는 두 계단씩
// 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다
// 마지막 도착 계단은 반드시 밟아야 한다

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	vector<int> scores(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
		cin >> scores[i];

	dp[0] = scores[0]; 
	dp[1] = scores[0] + scores[1];
	dp[2] = max(scores[0] + scores[2], scores[1] + scores[2]);

	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]);
	}

	cout << dp[n-1] << "\n";

	return 0;
}