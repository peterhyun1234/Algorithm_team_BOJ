//
//  14501.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/09/11.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, a, b;
    vector<pair<int, int>> money;
    
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> a >> b;
        money.push_back({a, b});
    }
    
    vector<int> dp(N + 1, 0);
    
    for (int i = N - 1; i >= 0; i --) {
        if (i + money[i].first > N) {
            dp[i] = dp[i + 1];
            continue;
        }
        dp[i] = max(dp[i + 1], money[i].second + dp[i + money[i].first]);
    }
    
    cout << dp[0] << '\n';
    
    return 0;
}
