// 농장에는 헛간이 많이 널려있고 재서기는 그 중에 하나에 숨어야 한다.
// 헛간의 개수는 N(2 <= N <= 20, 000)개

// 출력은 한줄로 이루어지며, 세 개의 값을 공백으로 구분지어 출력
// 숨어야 하는 헛간 번호
// 그 헛간까지의 거리
//  그 헛간과 같은 거리를 갖는 헛간의 개수

// 다익스트라로 1번 시작위치에서 모든 지점까지 가는 길이를 각각 구하고 
// 마지막에 정렬을 통해 가장 먼 거리

#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <climits>

using namespace std;

int INF = INT_MAX;

vector<int> graph[50001];

int dist[20001];
int n, m;

void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	int curr_node;

	while (pq.empty() == false) {
		curr_node = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[curr_node].size(); i++) { // curr_node에서 갈수 있는 경우만큼
			int distance = dist[graph[curr_node][i]];
			int new_distance = dist[curr_node] + 1; // weight는 전부 1

			if (new_distance < distance) { // 새로 탐색한 거리가 짧으면
				dist[graph[curr_node][i]] = new_distance;
				pq.push({ new_distance, graph[curr_node][i] });
			}
		}
	}
}


int main()
{
	int max_value;
	cin >> n >> m;

	int start, end, weight;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		// 방향 없음
		graph[start].push_back(end);
		graph[end].push_back(start);
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	dist[1] = 0;

	dijkstra();

	max_value = *max_element(dist + 1, dist + n);
	int count = 0;
	int idx;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == max_value) {
			count++;
			if (count == 1)
				idx = i;
		}
	}
	cout << idx << " " << max_value << " " << count << "\n";
}

