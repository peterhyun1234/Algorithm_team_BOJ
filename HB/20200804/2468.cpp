// 물에 잠기지 않는 안전한 영역이 최대로 몇 개
// 어떤 지역의 높이 정보는 행과 열의 크기가 각각 N인 2차원 배열 형태
// 비의 양에 따라서 물에 잠기지 않는 안전한 영역의 개수는 다름

// 내리는 비의 양에 따른 모든 경우를 다 조사해 보면 물에 잠기지 않는 안전한 영역의 개수


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1, };

vector<vector<int>> heights(100, vector<int>(100));
vector<vector<int>> path(100, vector<int>(100));


void dfs(int x, int y, int threshhold_height) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
		if (heights[nx][ny] < threshhold_height || path[nx][ny]) continue;
		path[nx][ny]++;
		dfs(nx, ny, threshhold_height);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int intput_height;
	int max_height = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> intput_height;
			heights[i][j] = intput_height;
			max_height = max(max_height, intput_height);
		}
	}
	int max_area_cnt = 0;
	for (int height = 1; height < max_height + 1; height++) {
		int cur_area_cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!path[i][j] && heights[i][j] > height) {
					path[i][j]++;
					dfs(i, j, height);
					cur_area_cnt++;
				}
			}
		}

		// init
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				path[i][j] = 0;
			}
		}

		max_area_cnt = max(max_area_cnt, cur_area_cnt);
	}

	cout << max_area_cnt << "\n";

	return 0;
}