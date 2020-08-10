//n개의 정점, m개의 간선이 주어집니다.
//간선의 정보는 1) 시작 점, 2) 도착 점, 3) 가중치. 간선의 양방향
//사진과 같이 시작 정점에서 다른 정점으로 최단 경로로 가기 위해 첫번째로 경유하는 정점들을 경로표로 출력하세요.
//n(1 <= n <= 200) 정점의 수, m(1 <= m <= 10000) 간선의 수

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct node {
    int end;
    int cost;
};

int n, m;

vector<node> house[201];
int dist[201];

struct cmp {
    bool operator () (node a, node b) {
        if (a.cost > b.cost) return true;
        else return false;
    }
};

int path[10000];

int main() {
    cin >> n >> m;

    int to, end, weight;
    for (int i = 0; i < m; i++) {
        cin >> to >> end >> weight;
        house[to].push_back({ end, weight });
        house[end].push_back({ to, weight });
    }

    priority_queue<node, vector<node>, cmp> pq;

    for (int start_node = 1; start_node <= n; start_node++) {

        for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
        dist[start_node] = 0;
        pq.push({ start_node, 0 });

        while (!pq.empty()) {
            node cur_node = pq.top();
            int cur_node_end = cur_node.end;
            pq.pop();

            for (int i = 0; i < house[cur_node_end].size(); i++) {
                node next = house[cur_node_end][i];
                int n_node = next.end;
                int n_cost = next.cost;

                if (dist[n_node] > dist[cur_node_end] + n_cost) {
                    dist[n_node] = dist[cur_node_end] + n_cost;
                    // c_node에서 cur_node_end로
                    path[n_node] = cur_node_end;
                    pq.push({ n_node, dist[n_node] });
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (i == start_node) {
                cout << "- ";
            }
            else if (path[i] == start_node) {
                cout << i << " ";
            }
            else {
                int cur_node = i;
                while (true) {
                    if (path[cur_node] == start_node) {
                        cout << cur_node << " ";
                        break;
                    }
                    else {
                        cur_node = path[cur_node];
                    }
                }
            }
        }
        cout << "\n";
    }
}