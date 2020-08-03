//
//  14502.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/01.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, map[10][10], pre_map[10][10], chk[10][10], max_cnt = -2147000000;
int dx[4] = {-1, 0, 1, 0};
int dy[4] ={0, 1, 0, -1};
vector<pair<int, int> > zero_vec;

void v_DFS(int x, int y) {
    chk[x][y] = 1;
    
    int nx, ny;
    for (int i = 0; i < 4; i ++) {
        nx = x + dx[i];
        ny = y + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (map[nx][ny] == 0 && chk[nx][ny] == 0) {
            chk[nx][ny] = 1;
            map[nx][ny] = 2;
            v_DFS(nx, ny);
        }
    }
    
    return ;
}

void spread_virus() {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 2 && chk[i][j] == 0) v_DFS(i, j);
        }
    }
    return ;
}

void reset_map() {
    memset(chk, 0, sizeof(chk));
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            map[i][j] = pre_map[i][j];
        }
    }
    
    return ;
}

int chk_area() {
    int area_cnt = 0;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (map[i][j] == 0) area_cnt ++;
        }
    }
    
    return area_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> map[i][j];
            pre_map[i][j] = map[i][j];
            if (map[i][j] == 0) zero_vec.push_back({i, j});
        }
    }
    
    for (int i = 0; i < zero_vec.size() - 2; i ++) {
        for (int j = i + 1; j < zero_vec.size() - 1; j ++) {
            for (int k = j + 1; k < zero_vec.size(); k ++) {
                map[zero_vec[i].first][zero_vec[i].second] = 1;
                map[zero_vec[j].first][zero_vec[j].second] = 1;
                map[zero_vec[k].first][zero_vec[k].second] = 1;
                spread_virus();
                
                int tmp = chk_area();
                if (tmp > max_cnt) max_cnt = tmp;
                
                reset_map();
            }
        }
    }
    
    cout << max_cnt << '\n';
        
    return 0;
}

/* 맵 확인
 cout << '\n';
 for (int i = 0; i < N; i ++) {
     for (int j = 0; j < M; j ++) {
         cout << map[i][j] << ' ';
     }
     cout << '\n';
 }
*/
/* 제로벡 확인
 for (int i = 0; i < zero_vec.size(); i ++) {
     cout << '{' << zero_vec[i].first << ' ' << zero_vec[i].second << "} ";
 }
 cout << '\n';
 */
