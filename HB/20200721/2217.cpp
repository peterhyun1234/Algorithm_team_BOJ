#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, weight_sum;
	cin >> n;
	vector<int> ropes(n);
	for (int i = 0; i < n; i++)
		cin >> ropes[i];

	sort(ropes.begin(), ropes.end());

	weight_sum = ropes[0] * n;

	for (int i = 1; i < n; i++) {
		weight_sum = max(weight_sum, ropes[i] * (n - i));
	}

	cout << weight_sum << "\n";

	return 0;
}