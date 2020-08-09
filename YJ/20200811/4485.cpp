//
//  4485.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/09.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

struct room {
    int x, y, dis;
    room(int a, int b, int c) {
        x = a;
        y = b;
        dis = c;
    }
};

struct cmp {
    bool operator() (room a, room b) {
        if (a.dis > b.dis) return true;
        else return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int size, seq = 1;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    priority_queue<room, vector<room>, cmp> Q;
    
    while(true) {
        cin >> size;
        if(size == 0) break;
        
        vector<vector<int>> cave(size, vector<int>(size, 0));
        vector<vector<int>> dist(size, vector<int>(size, INF));
    
        for (int i = 0; i < size; i ++) {
            for (int j = 0; j < size; j ++) {
                cin >> cave[i][j];
            }
        }
        
        dist[0][0] = cave[0][0];
        Q.push(room(0, 0, cave[0][0]));
        
        while(!Q.empty()) {
            int tmp_x = Q.top().x;
            int tmp_y = Q.top().y;
            int tmp_dis = Q.top().dis;
            Q.pop();
                        
            if (dist[tmp_x][tmp_y] < tmp_dis) continue;
            
            for (int i = 0; i < 4; i ++) {
                int nx = tmp_x + dx[i];
                int ny = tmp_y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= size || ny >= size) continue;
                int nxt_dis = cave[nx][ny] + tmp_dis;
                
                if (dist[nx][ny] > nxt_dis) {
                    dist[nx][ny] = nxt_dis;
                    Q.push(room(nx, ny, nxt_dis));
                }
            }
        
        }
       
        cout << "Problem " << seq << ": " << dist[size - 1][size - 1] << '\n';
        seq ++;
    }
    
    return 0;
}
