#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0, n = citations.size(), max_cit;
    
    sort(citations.begin(), citations.end(), greater<int>());
    max_cit = citations[0];
    
    for (int i = max_cit; i > 0; i --) {
        int bigger_cnt = 0, smaller_cnt = 0;
        for (int j = 0; j < n; j ++) {
            if (citations[j] >= i)
                bigger_cnt ++;
        }
        for (int j = 0; j < n; j ++) {
            if (citations[j] <= i)
                smaller_cnt ++;
        }
        if (bigger_cnt >= i && smaller_cnt <= i) {
            answer = i;
            break;
        }
    }
    
    return answer;
}
