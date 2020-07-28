// 체스판 위에 한 나이트
// 체스판의 크기는 l × l
// 나이트가 현재 있는 칸, 나이트가 현재 있는 칸
// Depth 설정때문에 DFS 불가능할듯 BFS로 ㄱㄱ

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> dx = { 2, 1, -1, -2, -2, -1, 1, 2 };
vector<int> dy = { 1, 2, 2, 1, -1, -2, -2, -1 };
vector<vector<int>> chess_board(300, vector<int>(300));

pair<int, int> current_position;
pair<int, int> destination;

int l;

void bfs(void) {
	queue<pair<int, int>> visted_queue;
	visted_queue.push(current_position);

	while (!visted_queue.empty()) {
		int x = visted_queue.front().first;
		int y = visted_queue.front().second;

		visted_queue.pop();

		if (x == destination.first && y == destination.second) {
			cout << chess_board[x][y] <<"\n";
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;

			if (chess_board[nx][ny]) continue;
			chess_board[nx][ny] = chess_board[x][y] + 1;
			visted_queue.push({ nx, ny });
		}
	}
}

void init_variables(void) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			chess_board[i][j] = 0;
		}
	}
	current_position = { 0, 0 };
	destination = { 0, 0 };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {

		init_variables();

		cin >> l;
		cin >> current_position.first >> current_position.second;
		cin >> destination.first >> destination.second;

		bfs();
	}

	return 0;
}