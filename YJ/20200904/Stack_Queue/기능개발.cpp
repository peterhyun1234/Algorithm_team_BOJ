#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<pair<int, int> > Q;

    for (int i = 0; i < speeds.size(); i ++) {
        Q.push_back({progresses[i], speeds[i]});
    }

    while (!Q.empty()) {
        for (int i = 0; i < Q.size(); i ++) {
            Q[i].first += Q[i].second;
        }

        int tmp = 0;
        while(true) {
            if (Q.front().first >= 100) {
                tmp ++;
                Q.pop_front();
            } else
                break;
        }
        if (tmp > 0)
            answer.push_back(tmp);
    }

    return answer;
}
