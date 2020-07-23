// 문제 잘 봐야할 듯 
// int 는 최대 20억정도(2^32 - 1)?
// 근데 이 문제에서 왜 long long을 써야하는 지 모르겠음

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int idx = 0;

	cin >> n >> k;

	map<long long, bool> num_check;
	vector<int> prime_numbers(n);
	priority_queue<long long, vector<long long>, greater<long long>> min_heap;

	for (int i = 0; i < n; i++) {

		cin >> prime_numbers[i];
	}

	min_heap.push(1);
	long long max_num = 0;

	while (true)
	{
		long long current_operator = min_heap.top();
		min_heap.pop();


		if (idx == k) {
			cout << current_operator << "\n";
			break;
		}

		for (int i = 0; i < n; i++) {
			long long current_num = current_operator * prime_numbers[i];

			if (min_heap.size() + idx > k && max_num < current_num) // 이 코드 없으면 메모리 초과;
				break;

			if (num_check[current_num] == 0) { // 중복 없으면

				max_num = max(max_num, current_num);
				min_heap.push(current_num);
				num_check[current_num] = 1;
			}
		}
		idx++;
	}

	return 0;
}