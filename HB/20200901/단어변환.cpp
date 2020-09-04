// begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾으려고 합니다.

#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int min_operations = INT_MAX;

bool dont_convert(string str, string compare_word){
    int n = str.size();
    int diff_cnt = 0;
    for(int i =0; i< n; i++){
        if(str[i] != compare_word[i]){
            diff_cnt++;
        }
    }
    
    if(diff_cnt == 1){
        return false;
    }else{
        return true;
    }
}

void dfs(string cur_str, string target_str, int depth, vector<string> words, vector<bool> path){
    int n = words.size();
    if(cur_str == target_str){
        min_operations = min(min_operations, depth);
        return;
    }
    for(int i = 0; i < n; i++){
        if(path[i]) continue;
        if(dont_convert(cur_str, words[i])) continue;
        
        path[i] = true;
        dfs(words[i], target_str, depth + 1, words, path);
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int n = words.size();
    vector<bool> path(n);
    
    if(find(words.begin(), words.end(), target) != words.end()){
        for(int i =0; i < n; i++){
            if(begin == words[i]){
                path[i] = true;
            }
        }
        
        dfs(begin, target, 0, words, path);
        
        if(min_operations == INT_MAX){
            answer = 0;
        }else{
            answer = min_operations;
        }
    }
    
    return answer;
}