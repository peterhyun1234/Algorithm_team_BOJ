//
//  1753.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/06.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define MAX 2147000000

using namespace std;

struct cmp {
    bool operator() (pair<int, int> A, pair<int, int> B) {
        if (A.second > B.second) return true;
        else return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int V, E, K, a, b, c;
    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> Q;
    vector<pair<int, int> > graph[20010];
    vector<int> dist(20010, MAX);
    
    cin >> V >> E >> K;
    
    for (int i = 0; i < E; i ++) {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    
    dist[K] = 0;
    Q.push({K, 0});
    
    while(!Q.empty()) {
        pair<int, int> edge = Q.top();
        Q.pop();
        
        int end = edge.first;
        int val = edge.second;
        
        if (val > dist[end]) continue;
        
        for (int i = 0; i < graph[end].size(); i ++) {
            int next_node = graph[end][i].first;
            int next_weight = graph[end][i].second + val;
            
            if (next_weight < dist[next_node]) {
                dist[next_node] = next_weight;
                Q.push({next_node, next_weight});
            }
        }
    }
    
    for (int i = 1; i <= V; i ++) {
        if (dist[i] != MAX) cout << dist[i] << '\n';
        else cout << "INF" << '\n';
    }
    
    return 0;
}
