#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<int> coins = { 500, 100, 50, 10, 5, 1};
	int input_money;
	int degree_of_coins = 0;
	int idx = 0;
	cin >> input_money;

	input_money = 1000 - input_money;

	while (input_money != 0) {
		if (input_money >= coins[idx]) {
			input_money -= coins[idx];
			degree_of_coins++;
		}
		else {
			idx++;
		}
	}

	cout << degree_of_coins << "\n";

	return 0;
}