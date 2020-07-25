#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector <int> cards(n);
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	int card_sum = 0;
	int max_sum = 0;
	for (int i = 0; i <= n - 3; i++) {
		for (int j = i + 1; j <= n - 2; j++) {
			for (int k = j + 1; k <= n - 1; k++) {
				card_sum = cards[i] + cards[j] + cards[k];
				if (card_sum <= m) {
					max_sum = max(max_sum, card_sum);
				}
			}
		}
	}
	cout << max_sum;

    return 0;
}