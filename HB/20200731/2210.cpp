// 5×5 크기의 숫자판
// 이동을 할 때에는 한 번 거쳤던 칸을 다시 거쳐도 됨
// 만들 수 있는 서로 다른 여섯 자리의 수들의 개수


#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int dx[4] = { 1,-1, 0,0 };
int dy[4] = { 0,0,1,-1 };

int n = 5;
int count_of_comdinations = 0;
bool duplicate_check[999999] = {false,};
vector<vector<int>> number_board(n, vector<int>(n));

void dfs(int x, int y, string current_num) {
	if (current_num.size() == n) {
		int int_curr_num = stoi(current_num);
		if (!duplicate_check[int_curr_num])
		{
			count_of_comdinations++;
			duplicate_check[int_curr_num] = true;
		}
        return ;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		dfs(nx, ny, current_num + (char)number_board[nx][ny]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> number_board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dfs(i, j, to_string(number_board[i][j]));	
		}
	}

	cout << count_of_comdinations << "\n";
	return 0;
}
