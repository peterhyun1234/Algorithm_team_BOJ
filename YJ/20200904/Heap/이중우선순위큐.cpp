#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    int cnt = 0;
    vector<int> answer;
    priority_queue<int> max_Q;
    priority_queue<int, vector<int>, greater<int>> min_Q;
    
    for (int i = 0; i < operations.size(); i ++) {
        string oper = operations[i];
        if (oper[0] == 'I') {
            cnt ++;
            max_Q.push(stoi(oper.substr(2, oper.length() - 2)));
            min_Q.push(stoi(oper.substr(2, oper.length() - 2)));
        } else {
            if (min_Q.empty() || max_Q.empty() || cnt == 0) continue;
            if (oper[2] == '-') {
                min_Q.pop();
                cnt --;
            } else {
                max_Q.pop();
                cnt --;
            }
        }
        if (cnt == 0) {
            while(!max_Q.empty()) {
                max_Q.pop();
            }
            while(!min_Q.empty()) {
                min_Q.pop();
            }
        }
    }
    
    if (cnt <= 0) return {0, 0};
    
    return {max_Q.top(), min_Q.top()};
}
