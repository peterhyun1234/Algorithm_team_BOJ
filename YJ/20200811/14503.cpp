//
//  14503.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/09.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, r, c, d, map[51][51] = { 0 }, cnt = 0;
    int dx[4] = {-1, 0, 1, 0}; // 북 동 남 서
    int dy[4] = {0, 1, 0, -1};
    
    cin >> N >> M;
    
    cin >> r >> c >> d;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> map[i][j];
        }
    }
    
    int x = r, y = c, dir = d;
    
    while(true) {
        if (map[x][y] == 0) {
            map[x][y] = 2;
            cnt ++;
        }
        
        int chk = 0;
        
        for (int i = 0; i < 4; i ++) {
            dir = dir - 1;
            if (dir < 0) dir = 3;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (map[nx][ny] == 0) {
                x = nx;
                y = ny;
                chk = 1;
                break;
            }
        }
        
        if (chk == 1) continue;
        
        int back_dir = dir - 2;
        
        if (back_dir == -2) back_dir = 2;
        if (back_dir == -1) back_dir = 3;
        
        x = x + dx[back_dir];
        y = y + dy[back_dir];
        
        if (map[x][y] == 1) break;
    }
    
    cout << cnt << '\n';
    
    return 0;
}
