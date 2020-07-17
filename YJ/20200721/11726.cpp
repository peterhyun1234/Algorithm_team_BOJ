//
//  11726.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int dp[1001];
    int n;
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] > 10007) dp[i] %= 10007;
    }
    
    cout << dp[n] % 10007 << '\n';
    
    return 0;
}
