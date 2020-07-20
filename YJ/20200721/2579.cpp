//
//  2579.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/19.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    int arr[301];
    int dp[301][2] = {0, };
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    dp[1][0] = arr[0] + arr[1];
    dp[1][1] = arr[1];
    
    for (int i = 2; i < T; i++) {
            dp[i][0] = arr[i] + dp[i - 1][1];
            dp[i][1] = arr[i] + max(dp[i - 2][0], dp[i - 2][1]);
    }
    
    cout << max(dp[T - 1][1], dp[T - 1][0]) << '\n';
    
    return 0;
}
