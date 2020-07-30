//
//  2178.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/30.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    int map[100][100], chk[100][100] = { 0 };
    queue<pair<int, int> > Q;
    pair<int, int> now;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    cin >> N >> M;
    cin.ignore();
    
    for (int i = 0; i < N; i++) {
        string tmp;
        getline(cin, tmp);
        for (int j = 0; j < M ; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }
    
    chk[0][0] = 1;
    Q.push({0, 0});
    
    while(!Q.empty()) {
        now = Q.front();
        Q.pop();
        
        if (now.first == N - 1 && now.second == M - 1) {
            cout << chk[N - 1][M - 1] << '\n';
            break;
        }
        
        for (int i = 0; i < 4; i ++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            
            if (chk[nx][ny] == 0 && map[nx][ny] == 1) {
                chk[nx][ny] = chk[now.first][now.second] + 1;
                Q.push({nx, ny});
            }
            
        }
    }
    
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << chk[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    return 0;
}
