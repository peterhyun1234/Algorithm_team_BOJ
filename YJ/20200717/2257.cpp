//
//  2257.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/15.
//  Copyright © 2020 황영준. All rights reserved.
//
#include <iostream>
#include <cstring>

using namespace std;

string s;
int answer = 0;
int temp[101] = { 0 };
int temp_idx = 0;
 
void recur(int idx, int sum) {
    if (idx == s.length()) {
        answer += sum;
        return;
    }
 
    if (s.at(idx) == 'H') {
        if (sum != 0)
            answer += sum;
        recur(idx + 1, 1);
    }
    else if (s.at(idx) == 'C') {
        if (sum != 0)
            answer += sum;
        recur(idx + 1, 12);
    }
    else if (s.at(idx) == 'O') {
        if (sum != 0)
            answer += sum;
        recur(idx + 1, 16);
    }
    else if (s.at(idx) >= '1' && s.at(idx) <= '9') {
        answer += (sum * (s.at(idx) - '0'));
        recur(idx + 1, 0);
    }
    else if (s.at(idx) == '(') {
        answer += sum;
        temp[temp_idx++] = answer;
        recur(idx + 1, 0);
    }
    else if (s.at(idx) == ')') {
        int t2 = answer + sum;
        answer = temp[--temp_idx];
        recur(idx + 1, t2 - temp[temp_idx]);
    }
}
 
int main(void) {
    cin >> s;
 
    memset(temp, 0, sizeof(temp));
 
    recur(0, 0);
    cout << answer << endl;
    return 0;
}
