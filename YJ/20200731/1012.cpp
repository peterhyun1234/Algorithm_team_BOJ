//
//  1012.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/30.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int map[51][51], chk[51][51], cnt = 0, M, N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y) {
    chk[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
        if (chk[xx][yy] == 0 && map[xx][yy] == 1) {
            chk[xx][yy] = 1;
            DFS(xx, yy);
        }
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T, K, x, y;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> M >> N >> K;
        
        for (int j = 0; j < K; j++) {
            cin >> y >> x;
            map[x][y] = 1;
        }
        
        for (int k = 0; k < N; k++) {
            for (int l = 0; l < M; l++) {
                if (map[k][l] == 1 && chk[k][l] == 0) {
                    DFS(k, l);
                    cnt ++;
                }
            }
        }
        
        cout << cnt << '\n';
        cnt = 0;
        memset(map, 0, sizeof(map));
        memset(chk, 0, sizeof(chk));
    }
    
    
    return 0;
}
