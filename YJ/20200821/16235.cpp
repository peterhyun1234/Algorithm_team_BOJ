//
//  16235.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/21.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, K, A[11][11], map[11][11], a, b, c, year = 0, result = 0;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<int> trees[11][11];
    cin >> N >> M >> K;
    
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            map[i][j] = 5;
        }
    }
    
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            cin >> A[i][j];
        }
    }
    
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        trees[a][b].push_back(c);
    }
    
    while (year < K) {
        for (int i = 1; i <= N; i ++) { // spring, summer
            for (int j = 1; j <= N; j ++) {
                
                vector<int> tmp[11][11];
                int erase_start = 0, cnt = 0;
                
                sort(trees[i][j].begin(), trees[i][j].end());
                
                for (int k = 0; k < trees[i][j].size(); k ++) {
                    if (trees[i][j][k] <= map[i][j]) {
                        map[i][j] -= trees[i][j][k];
                        trees[i][j][k] += 1;
                    } else {
                        erase_start = k;
                        for (int l = k; l < trees[i][j].size(); l ++) {
                            tmp[i][j].push_back(trees[i][j][l]);
                            cnt ++;
                        }
                        break;
                    }
                }
                if (tmp[i][j].size() > 0) {
                    for (int n = 0; n < tmp[i][j].size(); n ++) {
                        map[i][j] += (tmp[i][j][n] / 2);
                    }
                    trees[i][j].erase(trees[i][j].begin() + erase_start, trees[i][j].begin() + erase_start + cnt);
                }
            }
        }
        
        for (int i = 1; i <= N; i ++) { // fall
            for (int j = 1; j <= N; j ++) {
                for (int k = 0; k < trees[i][j].size(); k ++) {
                    if (trees[i][j][k] % 5 == 0) {
                        
                        for (int m = 0; m < 8; m ++) {
                            int nx = i + dx[m];
                            int ny = j + dy[m];
                            
                            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
                            
                            trees[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
        
        for (int i = 1; i <= N; i ++) { // winter
            for (int j = 1; j <= N; j ++) {
                map[i][j] += A[i][j];
            }
        }
        
        year ++;
    }
    
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            result += trees[i][j].size();
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
