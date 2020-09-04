#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, max_val = -2147000000;
    queue<pair<int, int>> Q;
    vector<int> graph[n + 1];
    vector<int> chk(n + 1, 0);
    
    for (int i = 0; i < edge.size(); i ++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    Q.push({1, 0});
    
    while(!Q.empty()) {
        int tmp = Q.front().first;
        int now_dist = Q.front().second;
        Q.pop();
        
        if (chk[tmp] == 0) {
            chk[tmp] = now_dist + 1;
            if (now_dist + 1 > max_val) max_val = now_dist + 1;
            
            for (int i = 0; i < graph[tmp].size(); i ++) {
                Q.push({graph[tmp][i], now_dist + 1});
            }
        }
    }
    
    for (int i = 1; i <= chk.size(); i ++) {
        if (chk[i] == max_val) answer++;
    }
    
    return answer;
}
