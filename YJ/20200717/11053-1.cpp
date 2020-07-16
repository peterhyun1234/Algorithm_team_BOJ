//
//  11053.cpp - 1
//  BOJprac
//
//  Created by 황영준 on 2020/07/16.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int arr[1000];
    int dp[1000];
    int T, result = 0;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    
    dp[0] = 1;
    result = 1;
    
    for (int i = 1; i < T; i++) {
        int max = 0;
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i] && dp[j] > max) {
                max = dp[j];
            }
        }
        dp[i] = max + 1;
        if (result < dp[i]) result = dp[i];
    }
    
    cout << result << '\n';
    
    return 0;
}
