#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    vector<char> cur_name(n, 'A');
    vector<bool> diff_position(n);
    int diff_cnt = 0;
    for(int i =0; i< n; i++){
        if(name[i] != cur_name[i]) {
            diff_position[i] = true;
            diff_cnt++;
        }
    }
    
    int cur_idx = 0;
    while(diff_cnt){
        
        // cur_name[cur_idx]에서 name[cur_idx]까지 최소 횟수
        // 1. 알파벳 순서대로
        int alpha_order = 0;
        if(cur_name[cur_idx] < name[cur_idx]){
            alpha_order = name[cur_idx] - cur_name[cur_idx];
        }else{
            alpha_order = cur_name[cur_idx] - name[cur_idx];
        }
        
        // 2. 알파벳 역순으로
        int r_alpha_order = 0;
        if(cur_name[cur_idx] < name[cur_idx]){
            r_alpha_order = (cur_name[cur_idx] - 'A') + ('Z' - name[cur_idx]);
        }else{
            r_alpha_order = (name[cur_idx] - 'A') + ('Z' - cur_name[cur_idx]);
        }
        
        answer += min(alpha_order, r_alpha_order);
        diff_position[cur_idx] = false;
        diff_cnt--;
        
        // 다음 다른 포지션을 찾을 때 최소 횟수
        if(!diff_cnt) break;
        
        // 1. 일반적인 순서대로
        int n_idx = cur_idx;
        int cursor_order_cnt = 0;
        while(true){
            if(!diff_position[n_idx]) break;
            
            if(cur_idx = n){
                n_idx = 0;
            }else{
                n_idx++;
            }
        
            cursor_order_cnt++;
        }
        
        int r_idx = cur_idx;
        int r_cursor_order_cnt = 0;
        while(true){
            if(!diff_position[r_idx]) break;
            
            if(cur_idx = n){
                r_idx = 0;
            }else{
                r_idx++;
            }
        
            r_cursor_order_cnt++;
        }
        
        if(cursor_order_cnt > r_cursor_order_cnt){
            answer += r_cursor_order_cnt;
            cur_idx = r_idx;
        }else{
            answer += cursor_order_cnt;
            cur_idx = n_idx;
        }
        
    }
    
    return answer;
}