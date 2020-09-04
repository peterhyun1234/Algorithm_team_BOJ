#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second > b.second)
            return true;
        else if (a.second == b.second) {
            if (a.first > b.first)
                return true;
            else
                return false;
        } else
            return false;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, idx = 0;
    // 들어온 시간, 작업 시간
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> PQ;
    
    sort(jobs.begin(), jobs.end());
    
    while (idx < jobs.size() || !PQ.empty()) {
        for (int i = idx; i < jobs.size(); i ++) {
            if (jobs[i][0] <= time) {
                PQ.push({jobs[i][0], jobs[i][1]});
                idx = i + 1;
            } else {
                idx = i;
                break;
            }
        }
        
        if (PQ.empty()) {
            time ++;
            continue;
        }
        
        int start = PQ.top().first;
        int period = PQ.top().second;
        PQ.pop();
        
        time += period;
        answer += time - start;
    }
    
    return answer / jobs.size();
}
