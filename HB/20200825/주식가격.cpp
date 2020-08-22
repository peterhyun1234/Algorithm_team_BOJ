#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i < prices.size(); i ++){
        int inc_cnt = 0;
        for(int j = i + 1; j < prices.size(); j ++){
            //cout << prices[i] << " vs " << prices[j] << "\n";
            if(prices[i] <= prices[j]){
                inc_cnt++;
            }else{
                inc_cnt++;
                break;
            }
        }
        answer.push_back(inc_cnt);
    }
    return answer;
}