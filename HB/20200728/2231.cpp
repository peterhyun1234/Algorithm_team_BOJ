#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int m = 0;
	cin >> n;

	int temp_n = n;
	int digit = 0;
	int num_sum = 0;

	while (temp_n) {
		temp_n = temp_n / 10;
		digit++;
	}

	
	for (int i = (n - digit * 9); i < n; i++) {
		num_sum = i;
		temp_n = i;

		while (temp_n) {
			num_sum += temp_n % 10;
			temp_n /= 10;
		}

		if (num_sum == n) {
			m = i;
			break;
		}
	}

	cout << m << "\n";

	return 0;
	
}