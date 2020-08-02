// 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
// 연구소는 크기가 N×M인 직사각형
// 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 
// 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.
// 0은 빈 칸, 1은 벽, 2는 바이러스
// 벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역
// 안전 영역의 최대 크기를 출력

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

vector<vector<int>> laboratory(9, vector<int>(9));
vector<vector<int>> laboratory_add_wall(9, vector<int>(9));

pair<int, int> first_position;
pair<int, int> second_position;
pair<int, int> third_position;

int degree_of_security = 0;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			laboratory_add_wall[i][j] = laboratory[i][j];
		}
	}
}

void input() {
	laboratory_add_wall[first_position.first][first_position.second] = 1;
	laboratory_add_wall[second_position.first][second_position.second] = 1;
	laboratory_add_wall[third_position.first][third_position.second] = 1;
}

void print() {
	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << laboratory_add_wall[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx > m || ny < 0 || ny > n) continue;
		if (laboratory_add_wall[ny][nx]) continue;
		laboratory_add_wall[ny][nx] = 2;
		dfs(ny, nx);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> laboratory[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == (n - 1) && j >= (m - 2)) continue;
			if (laboratory[i][j] == 0) {
				first_position = { i,j };
				for (int a = i; a < n; a++) {
					for (int b = 0; b < m; b++) {
						if (a == i && b <= j) continue;
						if (a == (n - 1) && b >= (m - 1)) continue;
						if (laboratory[a][b] == 0) {
							second_position = { a,b };
							for (int c = a; c < n; c++) {
								for (int d = 0; d < m; d++) {
									if (c == a && d <= b) continue;
									if (c == a && d == b) continue;
									if (laboratory[c][d] == 0) {
										third_position = { c,d };
										init();
										input();
										//print();

										int curr_degree_of_security = 0;
										for (int y = 0; y < n; y++) {
											for (int x = 0; x < m; x++) {
												if (laboratory[y][x] == 2) {
													dfs(y, x);
												}
											}
										}
										for (int y = 0; y < n; y++) {
											for (int x = 0; x < m; x++) {
												if (laboratory_add_wall[y][x] == 0) {
													curr_degree_of_security++;
												}
											}
										}
										degree_of_security = max(degree_of_security, curr_degree_of_security);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	cout << degree_of_security << "\n";

	return 0;
}