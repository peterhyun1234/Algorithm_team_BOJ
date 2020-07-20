#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int> lis;

int main() {
	int n;
	cin >> n;
	lis.push_back(INT_MAX);

	vector<int> input_nums;

	for (int i = 0; i < n; i++) {
		int input_num;
		cin >> input_num;
		input_nums.push_back(input_num);
	}

	for (int i = 0; i < n; i++) {
		int current_num = input_nums[i];
		if (lis.back() < current_num) {
			lis.push_back(current_num);
		}
		else {
			/*auto idx = lower_bound(lis.begin(), lis.end(), current_num) - lis.begin();
			lis[idx] = current_num;*/
			*lower_bound(lis.begin(), lis.end(), current_num) = current_num; //이렇게 사용하는 게 더 좋아보임
		}
	}
	cout << lis.size();
	return 0;
}