//
//  7562.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/30.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int chk[301][301];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        bool flag = false;
        int I;
        pair<int, int> x;
        queue<pair<int, int> > Q;
        pair<int, int> knight;
        pair<int, int> goal;
        
        cin >> I;
        cin >> knight.first >> knight.second;
        cin >> goal.first >> goal.second;
        
        chk[knight.first][knight.second] = 1;
        Q.push(knight);
        
        while(!Q.empty() && !flag) {
            x = Q.front();
            Q.pop();
            
            if (x.first == goal.first && x.second == goal.second) {
                cout << chk[knight.first][knight.second] - 1 << '\n';
                break;
            }
            
            for (int j = 0; j < 8; j++) {
                int nx = x.first + dx[j];
                int ny = x.second + dy[j];
                
                if (nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
                
                if (nx == goal.first && ny == goal.second) {
                    cout << chk[x.first][x.second] << '\n';
                    flag = true;
                    break;
                } else {
                    if (chk[nx][ny] == 0) {
                        chk[nx][ny] = chk[x.first][x.second] + 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        
        memset(chk, 0, sizeof(chk));
    }
    
    return 0;
}
