// 이번 선거에서는 최대한 공평하게 선거구를 획정
// 백준시는 N개의 구역
// 구역은 1번부터 N번까지 번호
// 구역을 두 개의 선거구
// 각 구역은 두 선거구 중 하나에 포함되어야 한다
// 선거구는 구역을 적어도 하나 포함
// 한 선거구에 포함되어 있는 구역은 모두 연결

// 공평하게 선거구를 나누기 위해 두 선거구에 포함된 인구의 차이를 최소로
// 인구 차이의 최솟값 출력, 두 선거구로 나눌 수 없는 경우에는 -1

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> populations;
vector<int> area_graph[11];

bool path[11];
int sum_of_area_1 = 0;
int sum_of_area_2 = 0;

int min_difference = -1;

bool find_duplicated(int node_idx, int target_node) {
	for (int i = 0; i < area_graph[node_idx].size(); i++) {
		if (area_graph[node_idx][0] == target_node) return false;
	}
	return true;
}

bool fully_connected() {
	for (int i = 0; i < n; i++) {
		if (path[i]) return false;
	}
	return true;
}

void bfs_area_2() {
	int start_idx = -1;
	for (int i = 0; i < n; i++) {
		if (!path[i]) {
			start_idx = i;
			break;
		}
	}

	if (start_idx == -1) {
		return;
	}

	queue<int> queue;
	queue.push(start_idx);
	path[start_idx] = true;
	sum_of_area_1 += populations[start_idx];


	while (!queue.empty()) {
		int curr_node = queue.front();
		queue.pop();

		for (int i = 0; i < area_graph[curr_node].size(); i++) {
			int next_node = area_graph[curr_node][i];

			if (path[next_node]) continue;

			queue.push(next_node);
			path[next_node] = true;
			sum_of_area_2 += populations[next_node];
		}
	}
}

void bfs_area_1(int start_idx) {
	int sum_of_area_1 = 0;
	int sum_of_area_2 = 0;
	memset(path, 0, sizeof(path));

	queue<int> queue;
	queue.push(start_idx);
	path[start_idx] = true;
	sum_of_area_1 += populations[start_idx];

	bfs_area_2();

	while (!queue.empty()) {
		int curr_node = queue.front();
		queue.pop();

		for (int i = 0; i < area_graph[curr_node].size(); i++) {
			int next_node = area_graph[curr_node][i];

			if (path[next_node]) continue;

			queue.push(next_node);
			path[next_node] = true;
			sum_of_area_1 += populations[next_node];

			bfs_area_2();

			if (fully_connected()) { // 그래프 구역 다 채워져 있는 상태
				if (sum_of_area_2 != 0) {
					min_difference = abs(sum_of_area_2 - sum_of_area_1);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int inputs_populations;
		cin >> inputs_populations;
		populations.push_back(inputs_populations);
	}

	for (int i = 0; i < n; i++) {
		int adjacent_nodes;
		cin >> adjacent_nodes;
		for (int j = 0; j < adjacent_nodes; j++) {
			int curr_adjacent_node;
			cin >> curr_adjacent_node;
			if (find_duplicated(i, curr_adjacent_node)) {
				area_graph[i].push_back(curr_adjacent_node);
				area_graph[curr_adjacent_node].push_back(i);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		bfs_area_1(i);
	}

	cout << min_difference << "\n";

	return 0;
}