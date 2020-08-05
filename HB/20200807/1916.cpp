// 첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)
// 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)
// 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보
// 출발 도시의 번호, 도착지의 도시 번호, 버스 비용

// 우선순위 큐를 이용한 다익스트라로 구현하면 좋을 듯


#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <climits>

using namespace std;

struct node {
    int end;
    int weight;
};
int INF = INT_MAX;
int n, m;
int starting_point, dest_point;

vector<node> bus_schdules[100000];
int dist[1001];

void dijkstra() {
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    pq.push({ 0, starting_point });

    while (!pq.empty()) {
        int curr_node = pq.top().second;
        pq.pop();

        for (int i = 0; i < bus_schdules[curr_node].size(); i++) {
            int before_weight = dist[bus_schdules[curr_node][i].end];
            int new_weight = dist[curr_node] + bus_schdules[curr_node][i].weight;

            if (new_weight < before_weight) {
                dist[bus_schdules[curr_node][i].end] = new_weight;
                pq.push({ new_weight, bus_schdules[curr_node][i].end });
            }
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int start, end, weight;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> weight;
        bus_schdules[start].push_back({ end, weight });
        //bus_schdules[end].push_back({ start, weight});
    }

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    cin >> starting_point >> dest_point;

    dist[starting_point] = 0;
    dijkstra();

    cout << dist[dest_point] << "\n";

    return 0;
}


