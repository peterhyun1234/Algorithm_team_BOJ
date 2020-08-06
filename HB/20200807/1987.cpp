// 첫째 줄에 R과 C  (1 ≤ R,C ≤ 20) 
// 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다

// DFS로 풀어보자 ㄱㄱ
// 중복 조회는 set을 써서 해보자!

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int r, c;
char board[20][20];
bool path[20][20];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool used_alphabets[30];

//set<char> used_alphabets;

int max_alphabets = 0;

//void dfs(int x, int y, int depth, set<char> used_alphabets) {
//
//	max_alphabets = max(max_alphabets, depth);
//
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i];
//		int ny = y + dy[i];
//
//		if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
//		if (path[ny][nx]) continue;
//		if (used_alphabets.find(board[ny][nx]) != used_alphabets.end()) continue;// 알파벳 중복 제거!
//
//		used_alphabets.insert(board[ny][nx]);
//		path[ny][nx] = true;
//		dfs(nx, ny, depth + 1, used_alphabets);
//		path[ny][nx] = false;
//	}
//
//}

void dfs(int x, int y, int depth) {

	max_alphabets = max(max_alphabets, depth);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
		if (path[ny][nx]) continue;
		if (used_alphabets[board[ny][nx] - 'A']) continue;// 알파벳 중복 제거!
		used_alphabets[board[ny][nx] - 'A'] = true;
		path[ny][nx] = true;
		dfs(nx, ny, depth + 1);
		used_alphabets[board[ny][nx] - 'A'] = false;
		path[ny][nx] = false;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}

	path[0][0] = true;
	//set<char> used_alphabets;
	//used_alphabets.insert(board[0][0]);

	used_alphabets[board[0][0] - 'A'] = true;

	dfs(0, 0, 1);

	cout << max_alphabets << "\n";

	return 0;
}