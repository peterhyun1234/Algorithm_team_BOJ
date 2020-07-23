// 첫째 줄에 출력하는 중앙값의 개수
// 둘째 줄에는 홀수 번째 수를 읽을 때 마다 구한 중앙값
// 한 줄에 10개

// 아이디어:
// min, map 힙을 활용해서 중앙값을 넣는다 => logN
// 각 힙의 사이즈를 비교해서
//

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int m, input_num;
		cin >> m;
		cout << (m + 1) / 2 << "\n";

		priority_queue<int, vector<int>, greater<int>> min_heap;
		priority_queue<int, vector<int>, less<int>> max_heap;

		for (int j = 1; j <= m; j++) {
			cin >> input_num;
			if (max_heap.size() == min_heap.size()) {
				if (min_heap.empty()) {
					max_heap.push(input_num);
				}
				else {
					if (min_heap.top() <= input_num) {
						int temp_num = min_heap.top();
						min_heap.pop();
						min_heap.push(input_num);
						input_num = temp_num;
					}
					max_heap.push(input_num);
				}
			}
			else {
				if (max_heap.top() > input_num) {
					int temp_num = max_heap.top();
					max_heap.pop();
					max_heap.push(input_num);
					input_num = temp_num;
				}
				min_heap.push(input_num);
			}

			if (j & 1) {
				cout << max_heap.top() << " ";
			}
		}
	}

	return 0;
}