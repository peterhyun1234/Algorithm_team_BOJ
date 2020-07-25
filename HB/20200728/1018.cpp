#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	string wb_string = "WBWBWBWB";
	string bw_string = "BWBWBWBW";

	vector<string> w_start_square;
	vector<string> b_start_square;

	vector<string> input_rectangular(n);

	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			w_start_square.push_back(wb_string);
			b_start_square.push_back(bw_string);
		}
		else {
			w_start_square.push_back(bw_string);
			b_start_square.push_back(wb_string);
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> input_rectangular[i];
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << input_rectangular[i][j] << " ";
	//	}
	//	cout << "\n";
	//}

	int min_diff = INT_MAX;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int current_diff = 0;
			int w_diffrence = 0;
			int b_diffrence = 0;
			for (int y = 0; y < 8; y++) {
				for (int x = 0; x < 8; x++) {
					if (input_rectangular[i + y][j + x] != w_start_square[y][x])
						w_diffrence++;
					if (input_rectangular[i + y][j + x] != b_start_square[y][x])
						b_diffrence++;
				}
			}
			current_diff = min(w_diffrence, b_diffrence);
			min_diff = min(current_diff, min_diff);
		}
	}

	cout << min_diff << "\n";

	return 0;
	
}