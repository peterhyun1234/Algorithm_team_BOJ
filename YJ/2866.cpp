//
//  2866.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/13.
//  Copyright © 2020 황영준. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

bool isdup(vector<string> strs) {
    for (int j = 1; j < strs.size(); j++) {
        if (strs[0] == strs[j]) return true;
    }
    return false;
}

void makeString(int R, int C, int count, deque<string> table) {
    vector<string> strs;
    
    for (int j = 0; j < C; j++) {
        string tmp;
        for (int k = 0; k < R; k++) {
            string tmp2 = table.at(k);
            char tmp3 = tmp2[j];
            tmp.push_back(tmp3);
        }
        strs.push_back(tmp);
    }
    
    if (isdup(strs)) {
        cout << count << '\n';
        return ;
    } else {
        table.pop_front();
        R --;
        count ++;
        makeString(R, C, count, table);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int count = 0;
    int R, C;
    cin >> R >> C;
    deque<string> table(R);
    
    for (int i = 0; i < R; i++) {
        cin >> table[i];
    }
    
    table.pop_front();
    R --;
    makeString(R, C, count, table);
    
    return 0;
}

// 시간초과
