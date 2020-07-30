// 배추흰지렁이 있으면 지렁이는 인접한 다른 배추로 이동 가능
// 최소의 배추흰지렁이 마리 수 출력

#include <iostream>
#include <vector>

using namespace std;

int m, n, k;

vector<int> dy = { 1,-1,0,0 };
vector<int> dx = { 0,0,1,-1 };

vector<vector <int>> cabbage_field(50, vector<int>(50));
vector<vector <int>> visited_field(50, vector<int>(50));

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			continue;
		if (cabbage_field[ny][nx] && !visited_field[ny][nx]) {
			visited_field[ny][nx]++;
			dfs(ny, nx);
		}
	}
}

void init_vectors(void) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cabbage_field[i][j] = 0;
			visited_field[i][j] = 0;
		}
	}
	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t) {

		init_vectors();

		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			cabbage_field[y][x]++;
		}

		int min_of_worm = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (cabbage_field[i][j] && !visited_field[i][j]) {
					min_of_worm++;
					visited_field[i][j]++;
					dfs(i, j);
				}
		
		cout << min_of_worm << "\n";


		t--;
	}

	return 0;
}