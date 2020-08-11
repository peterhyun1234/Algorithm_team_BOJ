// 화폐의 단위는 루피(rupee)
// 간혹 '도둑루피'라 불리는 검정색 루피
// 이걸 획득하면 오히려 소지한 루피가 감소
// 도둑루피만 가득한 N x N 크기의 동굴의 제일 왼쪽 위
// 동굴의 각 칸마다 도둑루피가 있는데
// 소지금을 잃게 된다. 링크는 잃는 금액을 최소로 하여 동굴 건너편까지 이동해야 하며, 
// 한 번에 상하좌우 인접한 곳으로 1칸씩 이동할 수 있다.
//

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <queue> 
#include <climits> 

using namespace std;

int INF = INT_MAX;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int graph[126][126];
int dist[126][126];
bool path[126][126];

struct node
{
	int cost;
	int y; 
	int x;
};

struct cmp {
	bool operator () (node a, node b) {
		if (a.cost > b.cost) return true;
		else return false;
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int cnt = 1;
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = INF;
				path[i][j] = false;
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> graph[i][j];

		priority_queue<node, vector<node>, cmp> pq;

		pq.push({ 0, 0, 0 });
		path[0][0] = true;

		while (!pq.empty()) {
			int y = pq.top().y;
			int x = pq.top().x;
			int cost = pq.top().cost;

			pq.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int ncost = cost + graph[ny][nx];
				if (0 <= ny && ny < n && 0 <= nx && nx < n) 
					if (!path[ny][nx] && dist[ny][nx] > ncost) {
						path[ny][nx] = true;
						dist[ny][nx] = ncost;
						pq.push({ ncost, ny, nx });
					}
			}
		}

		cout << "Problem " << cnt++ << ": " << graph[0][0] + dist[n - 1][n - 1] << "\n";
	}
	return 0;
}

