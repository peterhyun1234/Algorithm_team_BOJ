//
//  14500.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/27.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int map[500][500];
int tetro[19][4][2] = {
    // - 자 모양
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    
    // ㅁ 자 모양
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    
    // L 자 모양
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {1, 0}, {0, 1}, {0, 2}},
    
    // L 자 대칭
    {{0, 0}, {1, 0}, {2, 0}, {2, -1}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    
    // 꺾인 모양
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    
    // 꺾인 모양 대칭
    {{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    
    // ㅜ 자 모양
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {-1, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {-1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {1, 1}}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, result = 0;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                int sum = 0;
                for (int t = 0; t < 4; t++) {
                    int y = j + tetro[i][t][0];
                    int x = k + tetro[i][t][1];
                    
                    if (x < 0 || y < 0 || y >= N || x >= M) {
                        sum = 0;
                        break;
                    }
                    
                    sum += map[y][x];
                }
                result = max(result, sum);
            }
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
