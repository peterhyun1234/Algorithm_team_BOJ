// 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 25

int n;
int map[MAX][MAX];
vector<vector<int>> path(max, vector<int>(MAX));
int house_cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector <int> vec;

void dfs(int x, int y) {
	house_cnt++;
	path[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (map[nx][ny] == 1 && path[nx][ny] == false){
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++)	{
            map[i][j] = temp[j] - '0';
        }
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && path[i][j] == false) {
				house_cnt = 0;
				DFS(i, j);
				vec.push_back(house_cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;

	for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;

	return 0;
}