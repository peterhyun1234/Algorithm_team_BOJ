// 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향
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

int m, n, h;
int min_of_days = 0;

int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

struct tomato_position {
	int x;
	int y;
	int z;
};

queue<tomato_position> ripe_tomatos;

vector<vector<vector<int>>> box_spaces(100, vector<vector<int>>(100, vector<int>(100)));

void bfs(void) {

	while (!ripe_tomatos.empty()) {
		int x = ripe_tomatos.front().x;
		int y = ripe_tomatos.front().y;
		int z = ripe_tomatos.front().z;
		ripe_tomatos.pop();

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (0 <= nx && nx < h && 0 <= ny && ny < n && 0 <= nz && nz < m) {
				if (box_spaces[nx][ny][nz] == 0) {
					box_spaces[nx][ny][nz] = box_spaces[x][y][z] + 1;
					ripe_tomatos.push({ nx, ny, nz });
				}
			}
		}
		/*cout << "\n";
		for (int a = 0; a < h; a++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << box_spaces[a][i][j] << " ";
				}
			cout << "\n";
			}
		}
		cout << "\n";*/

	}

	for (int a = 0; a < h; a++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box_spaces[a][i][j] == 0) { // 안 익은 놈
					min_of_days = -1;
					return;
				}
				else if (box_spaces[a][i][j] > min_of_days)
					min_of_days = box_spaces[a][i][j];
			}
		}
	}

	min_of_days--;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> h;
	for (int a = 0; a < h; a++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int input_num;
				cin >> input_num;
				if (input_num == 1) {
					tomato_position curr_position;
					curr_position.x = a;
					curr_position.y = i;
					curr_position.z = j;
					ripe_tomatos.push(curr_position);
				}
				box_spaces[a][i][j] = input_num;
			}
		}
	}

	bfs();

	cout << min_of_days << "\n";

	return 0;
}