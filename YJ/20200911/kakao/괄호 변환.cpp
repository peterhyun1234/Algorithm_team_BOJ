#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrectStr(string s) {
    stack<char> stk;
    for (int i = 0; i < s.length(); i ++) {
        if (s[i] == '(') stk.push(s[i]);
        else {
            if (stk.size() <= 0) return false;
            stk.pop();
        }
    }
    return true;
}

string do_loop(string str) {
    if (str.length() == 0) return "";
    
    string u, v, ans;
    int bP, l_cnt = 0, r_cnt = 0;
    
    for (int i = 0; i < str.length(); i ++) {
        if (str[i] == '(') {
            u.push_back('(');
            l_cnt ++;
        }
        else {
            u.push_back(')');
            r_cnt ++;
        }
        if (i % 2 == 1) {
            if (l_cnt == r_cnt) {
                bP = i + 1;
                break;
            }
        }
    }
    
    for (int i = bP; i < str.length(); i ++) {
        v.push_back(str[i]);
    }
    
    if (isCorrectStr(u)) {
        ans += u;
        ans += do_loop(v);
    } else {
        ans.push_back('(');
        ans += do_loop(v);
        ans.push_back(')');
        for (int i = 1; i < u.length() - 1; i ++) {
            if (u[i] == '(')
                ans.push_back(')');
            else
                ans.push_back('(');
        }
    }
    
    return ans;
}

string solution(string p) {
    string answer = "";
    
    if (isCorrectStr(p)) return p;
    
    answer = do_loop(p);
    
    return answer;
}
