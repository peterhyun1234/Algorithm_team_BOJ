// 총 3개의 주사위가 있다. 그리고 이 주사위는 
// 각각 S1(2 ≤ S1 ≤ 20), 
// S2(2 ≤ S2 ≤ 20), 
// S3(2 ≤ S3 ≤ 40)개의 면

// 세개의 주사위를 동시에 던졌을 때 가장 높은 빈도로 나오는 세 주사위의 합

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> s(3);
	vector<int> sum(81,0);

	cin >> s[0] >> s[1] >> s[2];

	for (int i = 1; i <= s[0]; i++) {
		for (int j = 1; j <= s[1]; j++) {
			for (int k = 1; k < s[2]; k++) {
				sum[i + j + k]++;
			}
		}
	}
	int max_sum = 0;
	int answer = 0;
	for (int i = 1; i <= 80; i++) {
		if (max_sum < sum[i]) {
			answer = i;
			max_sum = sum[i];
		}
	}

	cout << answer << "\n";
	return 0;
}