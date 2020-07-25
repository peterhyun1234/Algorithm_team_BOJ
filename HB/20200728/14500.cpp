//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	int n, m;
//	cin >> n >> m;
//
//	vector<vector<int>> input_rectangular(n, vector<int>(m));
//	
//	vector<vector<pair<int, int>>> tetrominos(15);
//	
//	tetrominos[0] = { { 0,0 },{ 0,1 },{ 0,2 },{ 0,3 } };
//	tetrominos[1] = { { 0,0 },{ 1,0 },{ 2,0 },{ 3,0 } };
//
//	tetrominos[2]  = { { 0,0 },{ 0,1 },{ 1,0 },{ 1,1 } };
//
//	tetrominos[3] = { { 0,0 },{ 1,0 },{ 2,0 },{ 2,1 } };
//	tetrominos[4] = { { 0,0 },{ 1,0 },{ 0,1 },{ 0,2 } };
//	tetrominos[5] = { { 0,0 },{ 0,1 },{ 1,1 },{ 2,1 } };
//	tetrominos[6] = { { 1,0 },{ 1,1 },{ 1,2 },{ 0,2 } };
//
//	tetrominos[7]  = { { 0,0 },{ 1,0 },{ 1,1 },{ 2,1 } };
//	tetrominos[8] = { { 0,1 },{ 0,2 },{ 1,0 },{ 1,1 } };
//	tetrominos[9] = { { 0,0 },{ 0,1 },{ 1,1 },{ 1,2 } };
//	tetrominos[10] = { { 0,1 },{ 1,1 },{ 0,1 },{ 0,2 } };
//
//	tetrominos[11] = { { 0,1 },{ 1,0 },{ 1,1 },{ 1,2 } };
//	tetrominos[12] = { { 0,0 },{ 0,1 },{ 0,2 },{ 1,1 } };
//	tetrominos[13] = { { 0,0 },{ 1,0 },{ 2,0 },{ 1,1 } };
//	tetrominos[14] = { { 0,1 },{ 1,1 },{ 2,1 },{ 0,1 } };
//
//	//for(int i = 0; )
//
//	return 0;
//	
//}

// dfs를 이용한 풀이 방법
// 너무 노가다로 푸는 거 같아서 참조함
#include <iostream>

using namespace std;

int N, M, ans = -2e9;
int arr[501][501];
bool visit[501][501];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dfs(int y, int x, int cnt, int sum) {
    if (cnt == 4) {
        //max값 비교
        ans = ans < sum ? sum : ans;
        return;
    }
    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visit[ny][nx] == false) {
            visit[ny][nx] = true;
            dfs(ny, nx, cnt + 1, sum + arr[ny][nx]);
            visit[ny][nx] = false;
        }
    }
}

void findRemainder(int y, int x) {
    int sum = 0;
    //ㅗ
    if (y - 1 >= 0 && x + 2 < M) {
        sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y - 1][x + 1];
        ans = ans < sum ? sum : ans;
    }
    //ㅏ
    if (y + 2 < N && x + 1 < M) {
        sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1];
        ans = ans < sum ? sum : ans;
    }
    //ㅜ
    if (y + 1 < N && x + 2 < M) {
        sum = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
        ans = ans < sum ? sum : ans;
    }
    //ㅓ
    if (y + 2 < N && x - 1 >= 0) {
        sum = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x - 1];
        ans = ans < sum ? sum : ans;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visit[i][j] = true;
            dfs(i, j, 1, arr[i][j]);
            visit[i][j] = false;
            findRemainder(i, j);
        }
    }
    printf("%d", ans);
    return 0;
}