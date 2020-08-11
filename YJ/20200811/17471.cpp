//
//  17471.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/09.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, a, b, min_val = INT_MAX;
int people_of_city[11], graph[11][11] = { 0 }, cpy_graph[11][11], chk[11] = { 0 };

void reset_graph() {
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            graph[i][j] = cpy_graph[i][j];
        }
    }
}

struct Edge {
    int node, dist;
    Edge(int a, int c) {
        node = a;
        dist = c;
    }
};

struct cmp {
    bool operator() (Edge a, Edge b) {
        if (a.dist > b.dist) return true;
        else return false;
    }
};

bool dijkstra(vector<int> chkArr) {
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<Edge, vector<Edge>, cmp> Q;
    int startNode = chkArr.back();
    
    dist[startNode] = 0;
    Q.push(Edge(startNode, 0));
    
    while(!Q.empty()) {
        int now_node = Q.top().node;
        int now_dist = Q.top().dist;
        Q.pop();
        
        if (dist[now_node] < now_dist) continue;
        
        for (int i = 1; i <= N; i ++) {
            if (graph[now_node][i] == 1) {
                int next_node = i;
                int next_dist = 1 + now_dist;
                
                if (dist[next_node] > next_dist) {
                    dist[next_node] = next_dist;
                    Q.push(Edge(next_node, next_dist));
                }
            }
        }
    }
    
    for (int i = 1; i <= chkArr.size(); i ++) {
        if (dist[i] == INT_MAX) {
            return false;
        }
    } // 하나라도 갈 수 없을 경우
    return true; // 연결 O
}

void DFS(int Level) {
    if (Level == N + 1) {
        // chk가 모두 0, 모두 1인경우 제외
        bool flag = true;
        int tmp = chk[1];
        int sum1 = 0, sum2 = 0;
        vector<int> set1;
        vector<int> set2;
        
        for (int i = 2; i <= N; i ++) {
            if (chk[i] != tmp) flag = false ;
        }
        
        if (flag) return;
        
        
        for (int i = 1; i <= N; i ++) {
            if (chk[i] == 1) cout << i << ' ';
        }
        cout << '\n';
        
        
        for (int i = 1; i <= N; i ++) { // 다른 집합 간선 끊기
            if (chk[i] == 1) {
                set1.push_back(i);
                sum1 += people_of_city[i];
                for (int j = 1; j <= N; j ++) {
                    if (chk[j] == 0) graph[i][j] = 0;
                }
            } else {
                set2.push_back(i);
                sum2 += people_of_city[i];
                for (int j = 1; j <= N; j ++) {
                    if (chk[j] == 1) graph[i][j] = 0;
                }
            }
        }
        
        cout << sum1 << ' '<< sum2 << '\n';
        cout << dijkstra(set1) << ' ' << dijkstra(set2) << '\n';
        
        if (set1.size() == 1) {
            // set2만 검사
            if (dijkstra(set2) == false) {
                reset_graph();
                return;
            }
        } else if (set2.size() == 1) {
            // set1만 검사
            if (dijkstra(set1) == false) {
                reset_graph();
                return;
            }
        } else {
            // 둘다 검사
            if (dijkstra(set1) == false || dijkstra(set2) == false) {
                reset_graph();
                return;
            }
        }
        
        if (abs(sum1 - sum2) < min_val) min_val = abs(sum1 - sum2);
        reset_graph();
        
    } else {
        chk[Level] = 1;
        DFS(Level + 1);
        chk[Level] = 0;
        DFS(Level + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for (int i = 1; i <= N; i ++) {
        cin >> people_of_city[i];
    }
    
    for (int i = 1; i <= N; i ++) {
        cin >> a;
        for (int j = 0; j < a; j ++) {
            cin >> b;
            graph[i][b] = 1;
            cpy_graph[i][b] = 1;
        }
    }
    
    
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
    
     
    DFS(1);
    
    if (min_val == INT_MAX) cout << -1 << '\n';
    else cout << min_val << '\n';
    
    return 0;
}
