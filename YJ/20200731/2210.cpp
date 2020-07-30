//
//  2210.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/30.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

char map[5][5];
set<int> ans_sets;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int x, int y, int cnt, int cur) {
    if (cnt == 5) {
        ans_sets.insert(cur);
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            DFS(nx, ny, cnt + 1, cur * 10 + map[nx][ny]);
        }
    }
    
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            DFS(i, j, 0, map[i][j]);
        }
    }
    
    cout << ans_sets.size() << '\n';
    
    return 0;
}
