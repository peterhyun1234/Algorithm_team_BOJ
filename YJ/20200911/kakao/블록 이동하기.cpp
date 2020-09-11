#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct robot {
    pair<int, int> start_p;
    int time, direction;
    robot (int a, int b, int e, int f) {
        this -> start_p.first = a;
        this -> start_p.second = b;
        this -> time = e;
        this -> direction = f;
    }
};

bool range_check(int nx_1, int nx_2, int ny_1, int ny_2, int b_size) {
    if (nx_1 < 0 || nx_2 < 0 || ny_1 < 0 || ny_2 < 0 || nx_1 >= b_size
        || nx_2 >= b_size || ny_1 >= b_size || ny_2 >= b_size)
        return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0, board_size = board.size();
    int chk[101][101][4];
    queue<robot> Q;
    int dx[4] = {0, 1, 0, -1}; // 동 남 서 북
    int dy[4] = {1, 0, -1, 0};
    int rdx[4] = {1, 1, -1, -1};
    int rdy[4] = {1, -1, -1, 1};
        
    Q.push(robot(0, 0, 0, 0)); // 앞에 좌표, 뒤에 좌표, 시간, 방향
    chk[0][0][0] = 1;
    
    while(!Q.empty()) {
        robot t = Q.front();
        Q.pop();
        int x = t.start_p.first;
        int y = t.start_p.second;
        int dir = t.direction;
        int time = t.time;
       
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        
        if (x == board_size - 1 && y == board_size - 1) return time;
        if (xx == board_size - 1 && yy == board_size - 1) return time;
        
        // 동 남 서 북 이동
        int nx_1, nx_2, ny_1, ny_2;
        for (int i = 0; i < 4; i ++) {
            nx_1 = x + dx[i];
            ny_1 = y + dy[i];
            nx_2 = xx + dx[i];
            ny_2 = yy + dy[i];
            
            if (!range_check(nx_1, nx_2, ny_1, ny_2, board_size))
                continue;
            
            if (chk[nx_1][ny_1][dir] == 0 && board[nx_1][ny_1] != 1
                && board[nx_2][ny_2] != 1) {
                chk[nx_1][ny_1][dir] = time + 1;
                Q.push(robot(nx_1, ny_1, time + 1, dir));
            }
        }
        
        // 왼 기준 회전 2번
        for (int i = 0; i < 4; i ++) {
            if (dir % 2 == i % 2) continue;
            int nxx = x + dx[i];
            int nyy = y + dy[i];
            
            // 돌릴때 걸치는 좌표 ?
            int rx, ry;
            if (dir == 0 || dir == 3) {
                if (i < 2) {
                    rx = x + rdx[dir];
                    ry = y + rdy[dir];
                } else {
                    rx = x + rdx[i];
                    ry = y + rdy[i];
                }
            } else {
                if (i < 2) {
                    rx = x + rdx[i];
                    ry = y + rdy[i];
                } else {
                    rx = x + rdx[dir];
                    ry = y + rdy[dir];
                }
            }
            
            if (chk[x][y][i] != 0) continue;
            if (nxx < 0 || nyy < 0 || nxx >= board_size || nyy >= board_size)
                continue;
            if (rx < 0 || ry < 0 || rx >= board_size || ry >= board_size)
                continue;
            if (board[nxx][nyy] == 1) continue;
            if (board[rx][ry] == 1) continue;
            
            chk[x][y][i] = 1;
            Q.push(robot(x, y, time + 1, i));
        }
        
        // 오른 기준 회전 2번
        x = xx;
        y = yy;
        if (dir >= 2) dir %= 2;
        else dir += 2;
        for (int i = 0; i < 4; i ++) {
            if (dir % 2 == i % 2) continue;
            int nxx = x + dx[i];
            int nyy = y + dy[i];
            
            // 돌릴때 걸치는 좌표?
            int rx, ry;
            if (dir == 0 || dir == 3) {
                if (i < 2) {
                    rx = x + rdx[dir];
                    ry = y + rdy[dir];
                } else {
                    rx = x + rdx[i];
                    ry = y + rdy[i];
                }
            } else {
                if (i < 2) {
                    rx = x + rdx[i];
                    ry = y + rdy[i];
                } else {
                    rx = x + rdx[dir];
                    ry = y + rdy[dir];
                }
            }
            
            if (nxx < 0 || nyy < 0 || nxx >= board_size || nyy >= board_size)
                continue;
            if (rx < 0 || ry < 0 || rx >= board_size || ry >= board_size)
                continue;
            if (board[nxx][nyy] == 1) continue;
            if (board[rx][ry] == 1) continue;
            
            int ndir;
            if (i >= 2) ndir = i % 2;
            else ndir = i + 2;
            
            if (chk[nxx][nyy][ndir] != 0) continue;
            
            chk[nxx][nyy][ndir] = 1;
            Q.push(robot(nxx, nyy, time + 1, ndir));
        }
    }
    
    return answer;
}
