//
//  7569.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/31.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct tomato {
    int x, y, z;
    tomato(int i, int j, int k) {
        z = i;
        x = j;
        y = k;
    };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    queue<tomato> Q;
    priority_queue<int> PQ;
    int map[101][101][101], M, N, H;
    int dx[6] = {0, 0, -1, 0, 1, 0};
    int dy[6] = {0, 0, 0, 1, 0, -1};
    int dz[6] = {-1, 1, 0, 0, 0, 0};
    
    cin >> M >> N >> H;
    
    for (int i = 0; i < H; i ++) {
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k < M; k++) {
                cin >> map[i][j][k];
            }
        }
    }
    
    /*
    cout << '\n';
    for (int i = 0; i < H; i ++) {
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k < M; k++) {
                cout << map[i][j][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    */
     
    for (int i = 0; i < H; i ++) {
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k < M; k++) {
                if (map[i][j][k] == 1) Q.push(tomato(i, j, k));
            }
        }
    }
    
    while(!Q.empty()) {
        tomato t = Q.front();
        Q.pop();
        
        for (int i = 0; i < 6; i ++) {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];
            int nz = t.z + dz[i];
            
            if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
            
            if (map[nz][nx][ny] == 0) {
                map[nz][nx][ny] = map[t.z][t.x][t.y] + 1;
                Q.push(tomato(nz, nx, ny));
            }
        }
    }
    
    for (int i = 0; i < H; i ++) {
        for (int j = 0; j < N; j ++) {
            for (int k = 0; k < M; k++) {
                if (map[i][j][k] == 0) {
                    cout << -1 << '\n';
                    exit(0);
                } else PQ.push(map[i][j][k]);
            }
        }
    }
    
    cout << PQ.top() - 1 << '\n';
    
    return 0;
}
