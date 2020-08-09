//
//  1238.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/09.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

#define INF 2147000000

using namespace std;

struct Edge {
    int node, dist;
    Edge (int a, int b) {
        node = a;
        dist = b;
    }
};

struct cmp {
    bool operator() (Edge a, Edge b) {
        if (a.dist > b.dist) return true;
        else return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, X, a, b, c, max_dist = -2147000000;
    
    cin >> N >> M >> X;
    
    vector<Edge> graph[N + 1];
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        graph[a].push_back(Edge(b, c));
    }
     
    for (int i = 1; i <= N; i ++) {
        priority_queue<Edge, vector<Edge>, cmp> Q;
        
        Q.push(Edge(i, 0));
        dist[i][i] = 0;
        
        while(!Q.empty()) {
            int now = Q.top().node;
            int dis = Q.top().dist;
            Q.pop();
            
            if (dis > dist[i][now]) continue;
            
            for (int j = 0; j < graph[now].size(); j ++) {
                int nxt_node = graph[now][j].node;
                int nxt_dist = graph[now][j].dist + dis;
                
                if (dist[i][nxt_node] > nxt_dist) {
                    dist[i][nxt_node] = nxt_dist;
                    Q.push(Edge(nxt_node, nxt_dist));
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i ++) {
        if (dist[i][X] + dist[X][i] > max_dist) max_dist = dist[i][X] + dist[X][i];
    }
    
    cout << max_dist << '\n';
    
    return 0;
}
