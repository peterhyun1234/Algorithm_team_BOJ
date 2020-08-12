// N개의 도시
// 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M
// A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간
// 시간 C가 양수가 아닌 경우
// 벨만 포드로 ㄱㄱ

// 시간 복잡도는 모든 V 에 대하여, E 번 수행하기 때문에 O(|V|*|E|)
// 시간을 무한히 오래 전으로 되돌릴 수 있다면 첫째 줄에 -1 (음의 사이클)
// 다시 실행하면 dist가 변하는 특징으로 음의 사이클 찾기


// ㅈ같은 문제 예외처리 쓸데없이 많은거 같음

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
int main()
{
	int INF = INT_MAX;
	int n, m;
	vector<pair<int, int>> graph[501];
	long long dist[501]; // 2. 이거 때문에 출력 최ㅏ고ㅓㅏ가각@!!!@@@
	cin >> n >> m;

	int to, end, cost;
	for (int i = 0; i < m; i++)
	{
		cin >> to >> end >> cost;
		graph[to].push_back({ end, cost });
	}
	for (int i = 2; i < 501; i++)
	{
		dist[i] = INF;
	}

	dist[1] = 0;
	bool find_cycle = false;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			/*for (int k = 0; k < graph[j].size(); k++) {
				int before_cost = dist[graph[j][k].first];
				int new_cost = dist[j] + graph[j][k].second;

				if (before_cost > new_cost) {
					dist[graph[j][k].first] = new_cost;
					if (i == n) {
						find_cycle = true;
					}
				}
			}*/
			//1. 출력 초과 개때리고 싶다

			for (auto& temp : graph[j])
			{
				int next = temp.first;
				int next_weight = temp.second;

				if (dist[j] == INF) continue; // 3. 이거 때뭉ㄴ에!!!!

				if (dist[next] > dist[j] + next_weight)
				{
					dist[next] = dist[j] + next_weight;
					if (i == n)
					{
						find_cycle = true;
					}
				}
			}
		}
	}

	if (find_cycle)
	{
		cout << "-1" << "\n";
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == INF)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dist[i] << "\n";
			}
		}
	}
	return 0;
}