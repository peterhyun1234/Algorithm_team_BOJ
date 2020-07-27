// 보석이 총 N개
// 각 보석은 무게 Mi와 가격 Vi
// 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci
// 가방에는 최대 한 개의 보석만

// 출력: 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값\

// 이건 O(N^2) => 300000^2  > 1초 연산(10억 번)

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//struct jewelry
//{
//	int weight;
//	int price;
//};
//
//struct knapsack
//{
//	int weight;
//	int price = 0;
//};
//
//bool knapsack_cmp(knapsack a, knapsack b) {
//	return a.weight < b.weight;
//}
//
//bool jewelry_cmp(jewelry a, jewelry b) {
//	return a.weight < b.weight;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int n, k;
//	cin >> n >> k;
//
//	vector<jewelry> jewelrys(n);
//	vector<knapsack> knapsacks(k);
//
//	for (int i = 0; i < n; i++) {
//		cin >> jewelrys[i].weight >> jewelrys[i].price;
//	}
//	for (int i = 0; i < k; i++) {
//		cin >> knapsacks[i].weight;
//	}
//
//	sort(knapsacks.begin(), knapsacks.end(), knapsack_cmp);
//	sort(jewelrys.begin(), jewelrys.end(), jewelry_cmp);
//
//	int total_price = 0;
//
//	for (int i = 0; i < k; i++) {
//		int current_knapsack_weight = knapsacks[i].weight;
//		int max_price = 0;
//		int max_idx;
//		for (int j = 0; j < n; j++) {
//			if (current_knapsack_weight < jewelrys[j].weight) break;
//			if (jewelrys[j].price) {
//				max_price = max(max_price, jewelrys[j].price);
//				max_idx = j;
//			}
//		}
//		if (max_price) {
//			knapsacks[i].price = max_price;
//			total_price += max_price;
//			jewelrys[max_idx].price = 0;
//		}
//	}
//
//	cout << total_price << "\n";
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct jewelry
{
	int weight;
	int price;
};

struct knapsack
{
	int weight;
	int price = 0;
};

bool knapsack_cmp(knapsack a, knapsack b) {
	return a.weight < b.weight;
}

bool jewelry_cmp(jewelry a, jewelry b) {
	return a.weight < b.weight;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<jewelry> jewelrys(n);
	vector<knapsack> knapsacks(k);

	priority_queue<int> max_heap;

	for (int i = 0; i < n; i++) {
		cin >> jewelrys[i].weight >> jewelrys[i].price;
	}
	for (int i = 0; i < k; i++) {
		cin >> knapsacks[i].weight;
	}

	sort(knapsacks.begin(), knapsacks.end(), knapsack_cmp);
	sort(jewelrys.begin(), jewelrys.end(), jewelry_cmp);

	long long total_price = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		int current_knapsack_weight = knapsacks[i].weight;

		while (idx < n && jewelrys[idx].weight <= current_knapsack_weight) {
			max_heap.push(jewelrys[idx].price);
			idx++;
		}

		if (!max_heap.empty()) {
			total_price += max_heap.top();
			max_heap.pop();
		}

	}

	cout << total_price << "\n";

	return 0;
}