// 적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다
// N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑)

// 색상의 차이를 거의 느끼지 못하는 경우도 같은 색상

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int n;

vector<string> grid(100);
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int red_green[100][100] = { 0, };
int non_red_green[100][100] = { 0, };

void rg_dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];


		if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
		if (red_green[nx][ny]) continue;
		
		char const_color = 'B';
		if (grid[x][y] == 'R') {
			const_color = 'G';
		}else if (grid[x][y] == 'G') {
			const_color = 'R';
		}
		if (grid[x][y] == grid[nx][ny] || grid[nx][ny] == const_color) {
			red_green[nx][ny]++;
			rg_dfs(nx, ny);
		}
	}
}

void nrg_dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
		if (non_red_green[nx][ny]) continue;
		if (grid[x][y] != grid[nx][ny]) continue;
		non_red_green[nx][ny]++;
		nrg_dfs(nx, ny);
	}
}

void print() {
	cout << "\n";
	cout << "<rg>" <<"\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << red_green[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "<nrg>" << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << non_red_green[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}
	int rg_cnt = 0;
	int nrg_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!red_green[i][j]) {
				red_green[i][j]++;
				rg_dfs(i, j);
				rg_cnt++;
			}

			if (!non_red_green[i][j]) {
				non_red_green[i][j]++;
				nrg_dfs(i, j);
				nrg_cnt++;
			}

			print();

		}
	}

	cout << nrg_cnt << " " << rg_cnt << "\n";

	return 0;
}
