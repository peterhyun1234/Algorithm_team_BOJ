#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int l, p, v, max_days;
	int idx = 1;

	while (true) {
		l = 0;
		p = 0;
		v = 0;

		cin >> l >> p >> v;
		
		if (l == 0 && p == 0 && v == 0) {
			break;
		}

		int remainder_days = v % p < l ? v % p : l;
		max_days = (v / p) * l + remainder_days;

		cout << "Case " << idx << ": " << max_days << "\n";

		idx++;
	}

	return 0;
}