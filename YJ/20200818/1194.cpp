//
//  1194.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct room {
    int x, y, cnt, key;
    room (int a, int b, int c, int d) {
        x = a;
        y = b;
        cnt = c;
        key = d;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, result = -1, chk[51][51][64] = { 0 };
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    char map[51][51];
    queue<room> Q;
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> map[i][j];
            if (map[i][j] == '0') {
                Q.push(room(i, j, 0, 0));
                chk[i][j][0] = 1;
            }
        }
    }
    
    while(!Q.empty()) {
        room now_room = room(Q.front().x, Q.front().y, Q.front().cnt, Q.front().key);
        Q.pop();
        
        if (map[now_room.x][now_room.y] == '1') {
            result = now_room.cnt;
            break;
        }
        
        for (int i = 0; i < 4; i ++) {
            int nx = now_room.x + dx[i];
            int ny = now_room.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || chk[nx][ny][now_room.key] == 1 || map[nx][ny] == '#') continue;
            
            if (map[nx][ny] == '.' || map[nx][ny] == '0' || map[nx][ny] == '1') {
                chk[nx][ny][now_room.key] = 1;
                Q.push(room(nx, ny, now_room.cnt + 1, now_room.key));
            } else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
                int n_key = now_room.key | (1 << (int(map[nx][ny]) - 97));
                if (chk[nx][ny][n_key] == 0) {
                    chk[nx][ny][now_room.key] = 1;
                    chk[nx][ny][n_key] = 1;
                    Q.push(room(nx, ny, now_room.cnt + 1, n_key));
                }
            } else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F') {
                if (now_room.key & 1 << (int(map[nx][ny]) - 65)) {
                    chk[nx][ny][now_room.key] = 1;
                    Q.push(room(nx, ny, now_room.cnt + 1, now_room.key));
                }
            }
        }
    }
    
    cout << result << '\n';
     
    return 0;
}
