//
//  2468.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/01.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int N, map[101][101], chk[101][101];
int min_height = 2147000000, max_height = -2147000000, result = 1, cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init(int height) {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] <= height) map[i][j] = 0;
        }
    }
    memset(chk, 0, sizeof(chk));
    cnt = 0;
    return ;
}

void DFS(int x, int y) {
    int nx, ny;
    for (int i = 0; i < 4; i ++) {
        nx = x + dx[i];
        ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        
        if (map[nx][ny] != 0 && chk[nx][ny] == 0) {
            chk[nx][ny] = 1;
            DFS(nx, ny);
        }
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> map[i][j];
            if (map[i][j] < min_height) min_height = map[i][j];
            if (map[i][j] > max_height) max_height = map[i][j];
        }
    }
        
    for (int i = min_height; i < max_height; i++) {
        init(i);
        
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k < N; k ++) {
                if (map[j][k] != 0 && chk[j][k] == 0) {
                    DFS(j, k);
                    cnt ++;
                }
            }
        }
        
        if (cnt > result) result = cnt;
    }
    
    cout << result << '\n';
    
    return 0;
}
