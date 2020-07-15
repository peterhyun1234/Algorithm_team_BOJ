#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	int N;
	int weight_sum = 1;
	cin >> N;
	vector<int> plumb_weights(N);

	for (int i = 0; i < N; i++)
		cin >> plumb_weights[i];

	sort(plumb_weights.begin(), plumb_weights.end());


	for (int i = 0; i < N; i++) {
		if (weight_sum >= plumb_weights[i])
			weight_sum += plumb_weights[i];
		else {
			break;
		}
	}

	cout << weight_sum << "\n";

	return 0;
}