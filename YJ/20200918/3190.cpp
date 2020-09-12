//
//  3190.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/09/12.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct snake {
    int x, y, dir;
    snake(int a, int b, int c) {
        this -> x = a;
        this -> y = b;
        this -> dir = c;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K, L, map[101][101] = { 0 };
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    vector<pair<int, char>> path;
    vector<pair<int, pair<int, int>>> chg_dir;
    int a, b, c, cnt = 0, path_idx = 0, chk_idx = 0;
    bool flag = false;
    char d;
    
    cin >> N >> K;
    for (int i = 0; i < K; i ++) {
        cin >> a >> b;
        map[a - 1][b - 1] = 2; // 사과는 2
    }
    cin >> L;
    for (int i = 0; i < L; i ++) {
        cin >> c >> d;
        path.push_back({c, d});
    }
    
    snake tail = snake(0, 0, 0);
    snake head = snake(0, 0, 0);
    map[0][0] = 1; // 뱀은 1
    
    while(true) {
        cnt ++;
        
        int nx = head.x + dx[head.dir];
        int ny = head.y + dy[head.dir];
        
        if (flag) {
            for (int i = chk_idx; i < chg_dir.size(); i ++) {
                if (chg_dir[i].second.first == tail.x && chg_dir[i].second.second == tail.y) {
                    tail.dir = chg_dir[i].first;
                    chk_idx ++;
                    break;
                }
            }
        }
        
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) break;
        if (map[nx][ny] == 1) break;
        
        if (map[nx][ny] == 2) { // 다음칸에 사과가 있음
            map[nx][ny] = 1;
        } else { // 다음칸에 사과가 없음
            map[nx][ny] = 1;
            map[tail.x][tail.y] = 0;
            tail.x = tail.x + dx[tail.dir];
            tail.y = tail.y + dy[tail.dir];
        }
        head.x = nx;
        head.y = ny;
        
        for (int i = path_idx; i < path.size(); i ++) {
            if (cnt == path[i].first) {
                if (path[i].second == 'L') { // 왼쪽 회전
                    if (head.dir != 0) head.dir -= 1;
                    else head.dir = 3;
                } else { // 오른쪽 회전
                    if (head.dir != 3) head.dir += 1;
                    else head.dir = 0;
                }
                path_idx ++;
                chg_dir.push_back({head.dir, {head.x, head.y}});
                flag = true;
                break;
            }
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
