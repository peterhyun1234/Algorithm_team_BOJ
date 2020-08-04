// 모든 간선의 가중치는 10 이하의 자연수
// 정점의 개수 V와 간선의 개수 E (1≤V≤20,000, 1≤E≤300,000) 
// 둘째 줄에는 시작 정점의 번호 K
// E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 
// (u, v, w) 이는 u에서 v로 가는 가중치 w
// w는 10 이하의 자연수

// 예제를 보니 방향이 있는 그래프!!
// 벨만 포드의 시간 복잡도는 O(|V|*|E|)
// 다익스트라 O(V2)
// 개선된 알고리즘(pq 사용) -> O(ElogV)
// 우선 순위 큐를 사용하지 않으면 시간초과!

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef struct node {
    int end;
    int weight;
};

int INF = INT_MAX;
int start_node, v, e;

vector<node> graph[300001];
int dist[20001];

void dijkstra() {
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({ 0, start_node });
 
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> v >> e;
    cin >> start_node;

    int start, end, weight;
    for (int i = 0; i < e; i++) {
        cin >> start >> end >> weight;
        graph[start].push_back({ end, weight });
    }

    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }

    dist[start_node] = 0;
    dijkstra();

    for (int i = 1; i <= v; i++) {
        if (dist[i] != INF) {
            cout << dist[i] <<"\n";
        } else {
            cout << "INF\n";
        }
    }

    return 0;
}
