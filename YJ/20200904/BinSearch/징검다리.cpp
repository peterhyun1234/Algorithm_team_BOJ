#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num_of_rocks(int dist, vector<int> rocks) {
    int now_point = 0, cnt = 0;
    for (int i = 0; i < rocks.size(); i ++) {
        if (rocks[i] - now_point >= dist) {
            now_point = rocks[i];
            cnt ++;
        }
    }
    return cnt;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0, lft, rt, mid;
    
    sort(rocks.begin(), rocks.end());
    
    lft = 1;
    rt = distance;
    
    while(lft <= rt) {
        mid = (lft + rt) / 2;
        
        if (num_of_rocks(mid, rocks) >= rocks.size() - n) {
            lft = mid + 1;
            answer = mid;
        } else {
            rt = mid - 1;
        }
    }
    
    return answer;
}
