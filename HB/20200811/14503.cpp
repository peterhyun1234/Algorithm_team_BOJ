// 로봇 청소기가 주어졌을 때, 청소하는 영역의 개수
//왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
//왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
//네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
//네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

// d가 0인 경우에는 북쪽을, 1인 경우에는 동쪽을, 2인 경우에는 남쪽을, 3인 경우에는 서쪽

#include <iostream>
#include <queue>
using namespace std;

struct robot {
    int r, c, d;
};

robot input_robot;

int dr[] = { 0,-1,0,1 };
int dc[] = { -1,0,1,0 };

int reverse_r[] = { 1,0,-1,0 };
int reverse_c[] = { 0,-1,0,1 };

int n, m;
int cleaned_area = 0;;

int map[50][50];
bool path[50][50];


int main() {
    cin >> n >> m >> input_robot.r >> input_robot.c >> input_robot.d;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
           cin >> map[r][c];
        }
    }
    queue<robot> queue;
    queue.push(input_robot);
    while (!queue.empty()) {
        int r = queue.front().r;
        int c = queue.front().c;
        int d = queue.front().d;
        queue.pop();

        if (!path[r][c] && map[r][c] == 0) { // 1
            path[r][c] = true;
            cleaned_area++;
        }

        for (int i = 0; i < 4; ++i) {
            int next_r = r + dr[d]; 
            int next_c = c + dc[d];
            int next_d = (d + 3) % 4;

            if (!path[next_r][next_c] && map[next_r][next_c] == 0) { // 2.a
                input_robot.r = next_r;
                input_robot.c = next_c;
                input_robot.d = next_d;
                queue.push(input_robot);
                break;
            }
            else { 
                d = next_d; // 2.b
                if (i == 3) { // 2.c
                    r = r + reverse_r[d];
                    c = c + reverse_c[d];
                    i = -1;
                    if (map[r][c] == 1) break; // 2.d
                }
                continue;
            }
        }
    }

    cout << cleaned_area << "\n";

    return 0;
}