// 굵은 선은 벽을 나타내
// 점선은 벽이 없어서 지나다닐 수 있는 통로

// 1. 이 성에 있는 방의 개수
// 2. 가장 넓은 방의 넓이
// 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> node;

int n, m;
int curr_area, room_num;
int max_area, max_area_wo_wall;

int map[51][51];
int path[51][51];
int path_area[51 * 51];

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

queue<node> q;

void bfs(int r, int c) {
    room_num += 1;
    curr_area = 0;

    q.push(node(r, c));
    path[r][c] = room_num;
    curr_area += 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (path[nx][ny] != 0) continue;

            // 비트 값을 왼쪽으로 i번 이동 (0이면 1, 1이면 2)
            if ((map[x][y] & (1 << i)) == 0) {
                q.push(node(nx, ny));
                path[nx][ny] = room_num;
                curr_area += 1;
            }
        }
    }

    path_area[room_num] = curr_area;
    max_area = max(max_area, curr_area);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    room_num = 0;
    max_area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (path[i][j] == 0) {
                bfs(i, j);
            }
        }
    }

    max_area_wo_wall = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

                // 벽이 존재,  방번호가 다르면
                if ((map[i][j] & (1 << k)) && (path[i][j] != path[nx][ny])) {
                    int sum = path_area[path[i][j]] + path_area[path[nx][ny]];
                    max_area_wo_wall = max(max_area_wo_wall, sum);
                }
            }

        }
    }

    cout << room_num << "\n";
    cout << max_area << "\n";
    cout << max_area_wo_wall << "\n";

    return 0;
}