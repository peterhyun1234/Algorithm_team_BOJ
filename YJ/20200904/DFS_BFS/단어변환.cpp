#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0, word_cnt = words.size();
    vector<int> chk(word_cnt, 0);
    queue<pair<int, string>> Q;
    
    Q.push({0, begin});
    
    while(!Q.empty()) {
        int now_cnt = Q.front().first;
        string now_str = Q.front().second;
        Q.pop();
        
        if (now_str == target) {
            answer = now_cnt;
            break;
        }
        
        for (int i = 0; i < words.size(); i ++) {
            if (chk[i] == 1)
                continue;
            
            int diff_cnt = 0;
            for (int j = 0; j < now_str.size(); j ++) {
                if (now_str[j] != words[i][j])
                    diff_cnt ++;
            }
            
            if (diff_cnt == 1) {
                Q.push({now_cnt + 1, words[i]});
                chk[i] = 1;
            }
        }
    }
    
    return answer;
}
