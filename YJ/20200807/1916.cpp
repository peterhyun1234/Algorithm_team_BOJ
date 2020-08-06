//
//  1916.cpp
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

struct Edge {
    int end;
    int val;
    Edge(int a, int b) {
        end = a;
        val = b;
    }
};

struct cmp {
    bool operator () (Edge a, Edge b) {
        if (a.val > b.val) return true;
        else return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, a, b, c, start, destination;
    vector<Edge> graph[1010];
    priority_queue<Edge, vector<Edge>, cmp> Q;
    vector<int> dist(1010, MAX);
    
    cin >> N >> M;
    
    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        graph[a].push_back(Edge(b, c));
    }
    
    cin >> start >> destination;
    
    dist[start] = 0;
    Q.push(Edge(start, 0));
    
    while(!Q.empty()) {
        int now = Q.top().end;
        int dis = Q.top().val;
        Q.pop();
        
        if (dis > dist[now]) continue;
        
        for (int i = 0; i < graph[now].size(); i ++) {
            int next_node = graph[now][i].end;
            int next_dis = graph[now][i].val + dis;
            
            if (next_dis < dist[next_node]) {
                dist[next_node] = next_dis;
                Q.push(Edge(next_node, next_dis));
            }
        }
    }
    
    cout << dist[destination] << '\n';
    
    return 0;
}
