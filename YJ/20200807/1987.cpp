//
//  1987.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/06.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

int R, C, max_val = -2147000000;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char map[21][21];
int chk[21][21];
int visited[200];
string tmp;

void DFS(int x, int y, int cnt) {
    if (cnt > max_val) max_val = cnt;
    
    for (int i = 0; i < 4; i ++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
       
        if (chk[nx][ny] == 0 && visited[map[nx][ny]] == 0) {
            chk[nx][ny] = 1;
            visited[map[nx][ny]] = 1;
            DFS(nx, ny, cnt + 1);
            chk[nx][ny] = 0;
            visited[map[nx][ny]] = 0;
        }
    }
    
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> R >> C;
    
    cin.ignore();
    for (int i = 0; i < R; i ++) {
        getline(cin, tmp);
        for (int j = 0; j < C; j ++) {
            map[i][j] = tmp[j];
        }
    }
    
    chk[0][0] = 1;
    visited[map[0][0]] = 1;
    DFS(0, 0, 1);
    
    cout << max_val << '\n';
    
    return 0;
}
