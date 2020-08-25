// 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> remain_days;
    int n = progresses.size();
    for(int i = 0 ; i < n; i ++){
        remain_days.push_back(ceil((float)(100 - progresses[i])/speeds[i]));
    }
    
    int curr_remain_days = remain_days[0];
    int curr_task = 1;
    for(int i = 1; i < n; i++){

        if(curr_remain_days >= remain_days[i]){
            curr_task++;
        }else{
            answer.push_back(curr_task);
            curr_remain_days = remain_days[i];
            curr_task = 1;
        }
        
        if(i == n - 1) answer.push_back(curr_task);
    }
    
    return answer;
}