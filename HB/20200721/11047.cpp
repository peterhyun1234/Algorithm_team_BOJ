#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int degree_of_min = 0;

	cin >> n >> k;
	vector<int> coins(n);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	sort(coins.begin(), coins.end(), greater<>());

	for (int i = 0; i < n; i++) {
		while (k - coins[i] >= 0) {
			k -= coins[i];
			degree_of_min++;
		}
	}
	cout << degree_of_min << '\n';

	return 0;
}