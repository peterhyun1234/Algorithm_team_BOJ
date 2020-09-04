#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct node{
    int cost;
    int end;
};

vector<node> graph[20000];
int dist[20001];

void dijkstra(int start_node_num){
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, start_node_num});
    
    while(!pq.empty()){
        int cur_node_num = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < graph[cur_node_num].size(); i++){
            int before_distance = dist[graph[cur_node_num][i].end];
            int new_distance = dist[cur_node_num] + graph[cur_node_num][i].cost;

            if (new_distance < before_distance) {
                dist[graph[cur_node_num][i].end] = new_distance;
                pq.push({new_distance, graph[cur_node_num][i].end});
            }
        }
    }
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int edge_num = edge.size();
    
    vector<bool> path(n + 1);
    
    for(int i = 0; i < edge_num; i++){
        graph[edge[i][0]].push_back({1, edge[i][1]});
        graph[edge[i][1]].push_back({1, edge[i][0]});
    }
    
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    
    int start_node = 1;
    dist[start_node] = 0;
    dijkstra(start_node);
    
    int max_distance = *max_element(dist+1, dist+n+1);
    //cout << max_distance << "\n";
    for(int i = 1; i <= n; i++){
        if(dist[i] == max_distance) answer++;
    }
    return answer;
}