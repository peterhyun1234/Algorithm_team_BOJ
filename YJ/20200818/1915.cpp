//
//  1915.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, map[1000][1000] = { 0 }, dp[1000][1000] = { 0 }, max_val = -2147000000;
    string tmp;
    
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++) {
        cin >> tmp;
        for (int j = 0; j < m; j ++) {
            map[i][j] = tmp[j] - '0';
        }
    }
    
    for (int i = 0; i < n; i ++) {
        if (map[i][0] == 1) {
            dp[i][0] = 1;
            max_val = max(dp[i][0], max_val);
        }
    }
    
    for (int i = 0; i < m; i ++) {
        if (map[0][i] == 1) {
            dp[0][i] = 1;
            max_val = max(dp[0][i], max_val);
        }
    }
    
    max_val = dp[0][0]; // 이거 안해줘서 계속 틀림
    
    for (int i = 1; i < n; i ++) {
        for (int j = 1; j < m; j ++) {
            if (map[i][j] == 1) {
                int min_val = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                dp[i][j] = min_val + 1;
                if (dp[i][j] > max_val) max_val = dp[i][j];
            }
        }
    }
    
    cout << pow(max_val, 2) << '\n';
    
    return 0;
}
