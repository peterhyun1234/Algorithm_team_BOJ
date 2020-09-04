#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_possible(long long mid, int n, vector<int> times) {
    long long sum = 0;
    for (int i = 0; i < times.size(); i ++) {
        sum += mid / times[i];
    }
    if(sum >= n) return true;
    else return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0, lft, rt, mid;
    
    sort(times.begin(), times.end());
    
    rt = (long long)times[times.size() - 1] * n;
    lft = 1;
    
    while(lft <= rt) {
        mid = (lft + rt) / 2;
        
        if (is_possible(mid, n, times)) {
            rt = mid - 1;
            answer = mid;
        } else {
            lft = mid + 1;
        }
    }
    
    return answer;
}
