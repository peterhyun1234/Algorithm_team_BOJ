#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b) {
    string str_a = to_string(a);
    string str_b = to_string(b);
    if (str_a[0] > str_b[0])
        return true;
    else if (str_a[0] == str_b[0]) {
        if (str_a + str_b > str_b + str_a)
            return true;
        else
            return false;
    }
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), cmp);
    
    for (int i = 0; i < numbers.size(); i ++) {
        answer += to_string(numbers[i]);
    }
    
    bool flag = true;
    for (int i = 0; i < answer.size(); i ++) {
        if (answer[i] != '0')
            flag = false;
    }
    
    if (flag) return "0";
    return answer;
}
