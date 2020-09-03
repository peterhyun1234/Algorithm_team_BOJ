#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int pick_num = number.length() - k, start_idx = 0, whole_length = number.length();
    
    while(pick_num > 0) {
        char max_val = '0';
        for (int i = start_idx; i <= whole_length - pick_num; i ++) {
            if (number[i] > max_val) {
                max_val = number[i];
                start_idx = i + 1;
            }
        }
        answer.push_back(max_val);
        pick_num --;
    }
    
    return answer;
}
