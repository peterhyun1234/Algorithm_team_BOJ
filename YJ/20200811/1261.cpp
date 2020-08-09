//
//  1261.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/09.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

#define INF 2147000000

struct room {
    int x, y, cnt;
    room(int a, int b, int c) {
        x = a;
        y = b;
        cnt = c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<room> Q;
    string tmp;
    
    cin >> M >> N;
    
    vector<int> map[N];
    vector<vector<int>> dist(N, vector<int>(M, INF));
    
    cin.ignore();
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        for (int j = 0; j < M; j ++) {
            map[i].push_back(tmp[j] - '0');
        }
    }
    
    dist[0][0] = 0;
    Q.push(room(0, 0, 0));
    
    while(!Q.empty()) {
        room tmp = room(Q.front().x, Q.front().y, Q.front().cnt);
        Q.pop();
        
        if (dist[tmp.x][tmp.y] < tmp.cnt) continue;;
        
        for (int i = 0; i < 4; i ++) {
            int nx = tmp.x + dx[i];
            int ny = tmp.y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            
            int next_cnt = map[nx][ny] == 1 ? tmp.cnt + 1 : tmp.cnt;
            if (dist[nx][ny] > next_cnt) {
                dist[nx][ny] = next_cnt;
                Q.push(room(nx, ny, next_cnt));
            }
            
        }
    }
    
    cout << dist[N - 1][M - 1] << '\n';
    
    return 0;
}
