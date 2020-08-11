// 상근이와 친구들은 총 M명
// 입국심사대는 총 N개
// 입국심사관이 심사를 하는데 걸리는 시간은 사람마다 모두 다르다
// k번 심사대에 앉아있는 심사관이 한 명을 심사를 하는데 드는 시간은 Tk
// cpu thread가 n개 있고 프로세스가 m개 있다고 가정하고 스케줄링하는 알고리즘
// 츨력은 걸리는 시간의 최솟값

// 걸리는 시간을 이분 탐색!!

#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n, m;
	cin >> n >> m;

	vector<ll> immigration_times(n);
	ll min_immigration_time = 0;
	ll max_time = 0;
	for (int i = 0; i < n; i++) {
		cin >> immigration_times[i];
		max_time = max(max_time, immigration_times[i]);
	}

	ll time_left = 1;
	ll time_right = m * max_time;

	while (time_left <= time_right) {
		ll mid = time_left + (time_right - time_left) / 2;
		ll acceptable_people = 0;
		for (int i = 0; i < n; i++) {
			acceptable_people += mid / immigration_times[i];
		}

		if (acceptable_people < m) {
			time_left = mid + 1;
		}
		else {
			min_immigration_time = mid;
			time_right = mid - 1;
		}
	}

	cout << min_immigration_time << "\n";

	return 0;
}