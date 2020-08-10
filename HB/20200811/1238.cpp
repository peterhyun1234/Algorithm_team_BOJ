// N개의 숫자로 구분된 각각의 마을에 한 명의 학생
// N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티
// 이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti 시간 소비
// 각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다 (*2)


// 이 학생들은 최단 시간에 오고 가기를 원한다.
// 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도
// N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

int INF = INT_MAX;

using namespace std;

typedef struct node {
	int end;
	int weight;
};

int n, m, x;

int dist[1010];
int times_per_person[1010];
vector<node> graph[1010];

void dijkstra(int start_node_num)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start_node_num] = 0;
	pq.push({ 0, start_node_num });

	while (!pq.empty()) {
		int now_node = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[now_node].size(); i++) {
			int before_distance = dist[graph[now_node][i].end];
			int new_distance = dist[now_node] + graph[now_node][i].weight;

			if (new_distance < before_distance) {
				dist[graph[now_node][i].end] = new_distance;
				pq.push({ new_distance, graph[now_node][i].end });
			}
		}
	}
}

void init_dist() {
	for (int j = 1; j <= n; j++) {
		dist[j] = INF;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int to, end, weight;
		cin >> to >> end >> weight;
		graph[to].push_back({ end, weight });
	}

	for (int i = 1; i <= n; i++)
	{
		init_dist();
		dijkstra(i);
		times_per_person[i] = dist[x];
	}

	// 돌아가자 ㄱㄱ
	init_dist();
	dijkstra(x);

	for (int i = 1; i <= n; i++) { 
		times_per_person[i] += dist[i];
	}

	int max_distance = 0;
	for (int i = 1; i <= n; i++) {
		max_distance = max(max_distance, times_per_person[i]);
	}

	cout << max_distance << "\n";

	return 0;
}