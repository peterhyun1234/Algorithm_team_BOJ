//
//  14501.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/20.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int max (int a, int b) {
    return a > b ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, a, b, dp[100] = { 0 };
    vector<pair<int, int> > counsel(100);
    
    cin >> N;
    
    for (int i = 1; i <= N; i ++) {
        cin >> a >> b;
        counsel[i] = {a, b};
    }
    
    for (int i = N; i > 0; i --) {
        if (i + counsel[i].first > N + 1)
            dp[i] = dp[i + 1];
        else {
            dp[i] = max(dp[i + 1], (counsel[i].second + dp[i + counsel[i].first]));
        }
    }
    
    cout << dp[1] << '\n';
    
    return 0;
}
