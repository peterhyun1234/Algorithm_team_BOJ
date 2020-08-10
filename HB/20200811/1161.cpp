// 알고스팟 운영진이 모두 미로에 갇혔다.
// 미로는 N*M 크기이며, 총 1*1크기의 방으로 이루어져 있다. 
// 벽은 부수지 않으면 이동할 수 없다.
// 알고스팟의 무기 AOJ를 이용해 벽을 부수어 버릴 수 있다.
// 현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 벽을 최소 몇 개 부수어야 하는지

// 0은 빈 방을 의미하고, 1은 벽

// 최단 거리로 가는 게 최소로 부시는 걸까?
// 벽을 weight로 봐야하나? ㅇㅇ 이걸로 ㄱㄱ

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

int INF = INT_MAX;

using namespace std;

struct node {
    int x;
    int y;
    int dist;

    bool operator > (const node& n) const {
        return dist > n.dist;
    }
};

int n, m;

int map[101][101];
int dist[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dijkstra() {
    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({0, 0 ,0});
    dist[0][0] = 0;

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int d = pq.top().dist;
        pq.pop();

        if (x == n - 1 && y == m - 1) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
                dist[nx][ny] = dist[x][y] + map[nx][ny];
                pq.push({ nx, ny, dist[nx][ny] });
            }
        }
    }

}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            dist[i][j] = INF;
        }
    }

    dijkstra();

    cout << dist[n - 1][m - 1] << "\n";

    return 0;
}
