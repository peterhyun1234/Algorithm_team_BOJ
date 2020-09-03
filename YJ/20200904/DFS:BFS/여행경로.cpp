#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int max_cnt = 0, cnt = 0;
vector<string> answer, temp;
vector<bool> visit;

void DFS(string start, int cnt, vector<vector<string>>& tickets) {
    temp.push_back(start);
    
    if (max_cnt < cnt) {
        max_cnt = cnt;
        answer = temp;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (start == tickets[i][0] && !visit[i]) {
            visit[i] = true;
            DFS(tickets[i][1], cnt + 1, tickets);
            visit[i] = false;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    visit.resize(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    DFS("ICN", 0, tickets);
    return answer;
}
