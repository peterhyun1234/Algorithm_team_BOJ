//
//  1939.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/12.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, start, goal;
int chk[100001];
vector<pair<int, int> > nodes[100001];

bool possible(int weight) {
    queue<int> Q;
    Q.push(start);
    chk[start] = 1;
    
    while(!Q.empty()) {
        int now_node = Q.front();
        Q.pop();
        
        if (now_node == goal) return true;
        
        for (int i = 0; i < nodes[now_node].size(); i ++) {
            int next_node = nodes[now_node][i].first;
            int next_edge = nodes[now_node][i].second;
            
            if (next_edge >= weight && chk[next_node] == 0) {
                chk[next_node] = 1;
                Q.push(next_node);
            }
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int m, a, b, c, lt = 1, rt = 0, mid, res = 0;
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i ++) {
        cin >> a >> b >> c;
        nodes[a].push_back({b, c});
        nodes[b].push_back({a, c});
        if (c > rt) rt = c;
    }
    
    cin >> start >> goal;
    
    while(lt <= rt) {
        memset(chk, 0, sizeof(chk));
        
        mid = (lt + rt) / 2;
        if (possible(mid)) {
            lt = mid + 1;
            res = mid;
        } else {
            rt = mid - 1;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
