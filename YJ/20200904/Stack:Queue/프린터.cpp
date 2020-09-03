#include <string>
#include <vector>
#include <deque>

using namespace std;

struct work {
    int priority, location, cnt;
    work(int a, int b, int c) {
        priority = a;
        location = b;
        cnt = c;
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<work> Q;

    for (int i = 0; i < priorities.size(); i ++) {
        Q.push_back(work(priorities[i], i, 1));
    }

    while(true) {
        work tmp = work(Q.front().priority, Q.front().location, Q.front().cnt);

        bool flag = false;
        for (int i = 1; i < Q.size(); i ++) {
            if (Q[i].priority > tmp.priority) {
                flag = true;
                break;
            }
        }

        if (flag) {
            Q.pop_front();
            Q.push_back(tmp);
            continue;
        }

        if (tmp.location == location) {
            answer = tmp.cnt;
            break;
        }

        for (int i = 1; i < Q.size(); i ++) {
            Q[i].cnt ++;
        }
        Q.pop_front();
    }

    return answer;
}
