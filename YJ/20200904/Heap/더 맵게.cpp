#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> Q;

    for (int i = 0; i < scoville.size(); i ++) {
        Q.push(scoville[i]);
    }

    while(Q.top() < K && Q.size() >= 2) {
        int first = Q.top();
        Q.pop();
        int second = Q.top();
        Q.pop();
        if (first == 0 && second == 0) return -1;
        Q.push(first + second * 2);
        answer ++;
    }

    if (Q.top() >= K) return answer;
    else return -1;
}
