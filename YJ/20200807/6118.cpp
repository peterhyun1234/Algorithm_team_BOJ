//
//  6118.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/04.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, frt, back, x, max_dist = -2147000000, same_barn = 1;
    queue<int> Q;
    vector<int> barn[20010];
    int dist[20010] = { 0 };
    
    cin >> N >> M;
    for (int i = 0; i < M; i ++) {
        cin >> frt >> back;
        barn[frt].push_back(back);
        barn[back].push_back(frt);
    }
    
    Q.push(1);
    dist[1] = 1;
    
    while(!Q.empty()) {
        x = Q.front();
        Q.pop();
        
        for (int i = 0; i < barn[x].size(); i ++) {
            if (dist[barn[x][i]] == 0) {
                Q.push(barn[x][i]);
                dist[barn[x][i]] = dist[x] + 1;
                if (dist[x] + 1 > max_dist) max_dist = dist[x] + 1;
            }
        }
    }
    
    for (int i = 1; i <= N; i ++) {
        if (dist[i] == max_dist) {
            cout << i;
            break;
        }
    }
    
    sort(dist + 1, dist + N + 1, greater<>());
    
    for (int i = 2; i <= N; i ++) {
        if (dist[i] == dist[1]) same_barn ++;
        else break;
    }
    cout << ' ' << dist[1] - 1 << ' ' << same_barn << '\n';
    
    return 0;
}
