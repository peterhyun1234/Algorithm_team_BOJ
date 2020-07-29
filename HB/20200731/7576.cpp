// 익지 않은 토마토들도 있음
// 토마토가 모두 익을 때까지의 최소 날짜를 출력

// 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토
// -1은 토마토가 들어있지 않은 칸


// 토마토가 모두 익지는 못하는 상황이면 -1
// 저장될 때부터 모든 토마토가 익어있는 상태이면 0

// 다 익은 모양을 나타내려면 BFS쓰는 게 좋을 듯


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int m, n;
int min_of_days = 0;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<vector<int>> path(100, vector<int>(100));
vector<vector<int>> box_spaces(100, vector<int>(100));

void bfs(queue<pair<int, int>> ripe_tomatos) {

	while (!ripe_tomatos.empty()) {
		int x = ripe_tomatos.front().first;
		int y = ripe_tomatos.front().second;
		ripe_tomatos.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if ((box_spaces[nx][ny] == 0) && (path[nx][ny] == 0)) {
					path[nx][ny] = path[x][y] + 1;
					ripe_tomatos.push({ nx, ny });
					box_spaces[nx][ny] = 1;
				}
			}
		}
	}

    int max_of_path = 0;
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (path[i][j] == 0) { // 안 익은 놈
				min_of_days = -1;
				return;
			}
			else if (path[i][j] > max_of_path)
				max_of_path = path[i][j];
		}
	}

	min_of_days = max_of_path - 1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
    
    queue<pair<int, int>> ripe_tomatos;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input_num;
			cin >> input_num;
			if (input_num == 1) {
				ripe_tomatos.push({ i, j });
			}
			box_spaces[i][j] = input_num;
			path[i][j] = input_num;
		}
	}

	bfs(ripe_tomatos);

	cout << min_of_days << "\n";

	return 0;
}