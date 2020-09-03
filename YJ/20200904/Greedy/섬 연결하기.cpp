#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int, int>> map[100]; // cost, 목적지 저장
    vector<int> chk(100, 0);
    priority_queue<pair<int, int>> Q;
    
    for (int i = 0; i < costs.size(); i ++) {
        map[costs[i][0]].push_back({-costs[i][2], costs[i][1]});
        map[costs[i][1]].push_back({-costs[i][2], costs[i][0]});
    }
    
    Q.push({0, 0});
    
    while(!Q.empty()) {
        int v = Q.top().second;
        int cost = -Q.top().first;
        Q.pop();
        
        if (chk[v] == 0) {
            chk[v] = 1;
            answer += cost;
            for (int i = 0; i < map[v].size(); i ++) {
                Q.push({map[v][i].first, map[v][i].second});
            }
        }
    }
    
    return answer;
}
