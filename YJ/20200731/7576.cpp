//
//  7576.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/30.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int> > Q;
pair<int, int> x;
int map[1000][1000], M, N, cnt = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M >> N;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) Q.push({i, j});
        }
    }
    
    while(!Q.empty()) {
        x = Q.front();
        Q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x.first + dx[i];
            int ny = x.second + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            
            if (map[nx][ny] == 0) {
                map[nx][ny] = map[x.first][x.second] + 1;
                Q.push({nx, ny});
            }
            
        }
    }
    
    priority_queue<int> pq;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (flag) break;
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                flag = true;
                break;
            }
            pq.push(map[i][j]);
        }
    }
    
    if (flag) cout << -1 << '\n';
    else cout << pq.top() - 1 << '\n';
    
    /*
    cout << '\n';
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j++ ){
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    return 0;
}
