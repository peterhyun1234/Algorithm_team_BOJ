//
//  1325.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/16.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, a, b, max_num = 0;
    
    cin >> N >> M;
    
    vector<int> network[N + 1];
    vector<int> possible_num(N + 1, 0);
    
    for (int i = 0; i < M; i ++) {
        cin >> a >> b;
        network[a].push_back(b);
    }
    
    for (int i = 1; i <= N; i ++) {
        vector<int> chk(N + 1, 0);
        queue<int> Q;
        Q.push(i);
        chk[i] = 1;
        
        while(!Q.empty()) {
            int believer = Q.front();
            Q.pop();
            
            for (int j = 0; j < network[believer].size(); j ++) {
                int target = network[believer][j];
                if (chk[target] == 0) {
                    chk[target] = 1;
                    possible_num[target] ++;
                    if (possible_num[target] > max_num) max_num = possible_num[target];
                    Q.push(target);
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i ++) {
        if (possible_num[i] == max_num) cout << i << ' ';
    }
    
    return 0;
}
