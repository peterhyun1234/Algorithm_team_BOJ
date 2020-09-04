#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0, now_weight = 0, last_idx = people.size() - 1;
    
    vector<bool> chk(people.size(), false);
    
    sort(people.begin(), people.end(), greater<int>());
    
    for (int i = 0; i < people.size(); i ++) {
        if (chk[i] == false) {
            chk[i] = true;
            int weight_sum = people[i];
            for (int j = last_idx; j > i; j --) {
                if (weight_sum + people[j] <= limit) {
                    chk[j] = true;
                    weight_sum += people[j];
                    last_idx --;
                } else
                    break;
            }
            answer ++;
        }
    }
    
    return answer;
}
