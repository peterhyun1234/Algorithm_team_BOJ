//
//  2667.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/31.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T, map[30][30], chk[30][30], cnt = 0;
vector<int> apart_num;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void DFS(int row, int col) {
    int nx, ny;
    
    for (int i = 0; i < 4; i ++) {
        nx = row + dx[i];
        ny = col + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= T || ny >= T) continue;
        
        if (map[nx][ny] == 1 && chk[nx][ny] == 0) {
            chk[nx][ny] = 1;
            cnt ++;
            DFS(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string tmp;
    
    cin >> T;
    cin.ignore();
    
    for (int i = 0; i < T; i ++) {
        getline(cin, tmp);
        for (int j = 0; j < T; j ++) {
            map[i][j] = tmp[j] - '0';
        }
    }
   
    /*
    cout << '\n';
    for (int i = 0; i < T; i ++) {
        for (int j = 0; j < T; j ++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    for (int i = 0; i < T; i ++) {
        for (int j = 0; j < T; j ++) {
            if (map[i][j] == 1 && chk[i][j] == 0) {
                cnt = 1;
                chk[i][j] = 1;
                DFS(i, j);
                if (cnt != 0) apart_num.push_back(cnt);
            }
        }
    }
    
    sort(apart_num.begin(), apart_num.end());
    
    cout << apart_num.size() << '\n';
    for (int i = 0; i < apart_num.size(); i ++) {
        cout << apart_num[i] << '\n';
    }
    
    return 0;
}
/* 처음에 생각 못했던 것
 2
 01
 10
 초깃값 초기화 안함
 
 TC
 7
 0110100
 0110101
 1110101
 0000111
 0100000
 0111110
 0111000
 
*/
