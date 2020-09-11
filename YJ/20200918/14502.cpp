//
//  14502.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/09/11.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, answer = -2147000000;
int map[8][8], copy_map[8][8], chk[8][8];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> zero_kan;

void spread_virus(int r, int c) {
    
    for (int i = 0; i < 4; i ++) {
        int nx = r + dx[i];
        int ny = c + dy[i];
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        
        if (map[nx][ny] == 0 && chk[nx][ny] == 0) {
            chk[nx][ny] = 1;
            map[nx][ny] = 2;
            spread_virus(nx, ny);
        }
    }
}

int check_room_num() {
    int room_num = 0;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (map[i][j] == 2) {
                chk[i][j] = 1;
                spread_virus(i, j);
            }
        }
    }
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            if (map[i][j] == 0) room_num ++;
            map[i][j] = copy_map[i][j];
        }
    }
    
    memset(chk, 0, sizeof(chk));
    
    return room_num;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < M; j ++) {
            cin >> map[i][j];
            if (map[i][j] == 0) zero_kan.push_back({i, j});
            copy_map[i][j] = map[i][j];
        }
    }
    
    for (int i = 0; i < zero_kan.size() - 2; i ++) {
        for (int j = i + 1; j < zero_kan.size() - 1; j ++) {
            for (int k = j + 1; k < zero_kan.size(); k ++) {
                map[zero_kan[i].first][zero_kan[i].second] = 1;
                map[zero_kan[j].first][zero_kan[j].second] = 1;
                map[zero_kan[k].first][zero_kan[k].second] = 1;
                answer = max(check_room_num(), answer);
            }
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
