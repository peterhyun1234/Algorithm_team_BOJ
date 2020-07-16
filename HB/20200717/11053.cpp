// 절대 좋은 코드는 아님;; 예외처리 해줘야할게 많은데
// 1초라서 1000*1000*1000 가능했기 때문에 통과한 코드..;

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int n;
	int max_num = 0;
	cin >> n;

	vector<int> input_num(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> input_num[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (input_num[i] > input_num[j]) {
				dp[i] = (dp[i] > (dp[j] + 1)) ? dp[i] : (dp[j] + 1);
			}
		max_num = max_num > dp[i] ? max_num : dp[i];
	}

	cout << max_num << "\n";


	return 0;
}
