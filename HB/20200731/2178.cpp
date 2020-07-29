// N×M크기의 배열로 표현되는 미로
// 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸
// (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수

// 계속 선택해야하기 때문에 BFS가 맞을 듯!


#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0,0,1,-1 };

pair<int, int> current_position = { 0,0 };
pair<int, int> destination = { 0,0 };

int n, m; 
vector<vector<int>> maze(100, vector<int>(100));
vector<vector<int>> path(100, vector<int>(100));

void bfs(void) {
	queue<pair<int, int>> visted_queue;
	visted_queue.push(current_position);
	//init
	path[current_position.first][current_position.second] = 1;
	destination = { n, m };

	while (!visted_queue.empty()) {
		int x = visted_queue.front().first;
		int y = visted_queue.front().second;

		visted_queue.pop();

		if (x == (destination.first - 1) && y == (destination.second - 1)) {
			cout << path[x][y] << "\n";
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (!maze[nx][ny]) continue;
			if (path[nx][ny]) continue;
			path[nx][ny] = path[x][y] + 1;
			visted_queue.push({ nx, ny });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string input_str;
		cin >> input_str;
		for (int j = 0; j < m; j++) {
			if (input_str[j] == '1') {
				maze[i][j] = 1;
			}
		}
	}
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];

		}
	}*/

	bfs();


	return 0;
}