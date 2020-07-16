//
//  9251.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/16.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string A, B;
    
    cin >> A >> B;
    
    int dp[1001][1001] = {0, };
    
    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    
    cout << dp[A.size()][B.size()] << '\n';
    
    return 0;
}
