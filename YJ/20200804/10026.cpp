//
//  10026.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/01.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int N, chk[101][101], cnt_1 = 0, cnt_2 = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[101][101];
string tmp;

void ch_map() {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (map[i][j] == 'G') map[i][j] = 'R';
        }
    }
    memset(chk, 0, sizeof(chk));
    return ;
}

void DFS(int x, int y) {
    int nx, ny;
    for (int i = 0; i < 4; i ++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (chk[nx][ny] == 0 && map[nx][ny] == map[x][y]) {
            chk[nx][ny] = 1;
            DFS(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    cin.ignore();
    
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        for (int j = 0; j < N; j ++) {
            map[i][j] = tmp[j];
        }
    }
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            if (chk[i][j] == 0) {
                DFS(i, j);
                cnt_1 ++;
            }
        }
    }
    
    ch_map();
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            if (chk[i][j] == 0) {
                DFS(i, j);
                cnt_2 ++;
            }
        }
    }
    
    cout << cnt_1 << ' ' << cnt_2 << '\n';
    
    return 0;
}
