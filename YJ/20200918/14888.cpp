//
//  14888.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/09/12.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, A[11], tmp;
int min_val = 2147000000, max_val = -2147000000;
vector<int> opers; // 0 덧셈, 1 뺄셈, 2 곱셈, 3 나눗셈
vector<int> chk;

void DFS(string permu) {
    if (permu.size() >= opers.size()) {
        int ans = A[0];
        for (int i = 0; i < N - 1; i ++) {
            if (permu[i] == '+') {
                ans += A[i + 1];
            } else if (permu[i] == '-') {
                ans -= A[i + 1];
            } else if (permu[i] == '*') {
                ans *= A[i + 1];
            } else {
                ans /= A[i + 1];
            }
        }
        min_val = min(min_val, ans);
        max_val = max(max_val, ans);
    } else {
        for (int i = 0; i < opers.size(); i ++) {
            if (chk[i] == 0) {
                chk[i] = 1;
                switch (opers[i]) {
                    case 0: permu.push_back('+');
                        break;
                    case 1: permu.push_back('-');
                        break;
                    case 2: permu.push_back('*');
                        break;
                    case 3: permu.push_back('/');
                        break;
                }
                DFS(permu);
                chk[i] = 0;
                permu.pop_back();
            }
        }
    }
    
    return ;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> A[i];
    }
    for (int i = 0; i < 4; i ++) {
        cin >> tmp;
        for (int j = 0; j < tmp; j ++) {
            opers.push_back(i);
        }
    }
    
    chk.resize(opers.size(), 0);
    
    DFS("");
    
    cout << max_val << '\n' << min_val << '\n';
    
    return 0;
}
