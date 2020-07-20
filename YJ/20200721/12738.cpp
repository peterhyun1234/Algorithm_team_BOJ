//
//  12738.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/19.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
int N;
int arr[MAX];
int dp[MAX];

int LIS(void) {
    int idx = 0;
    dp[idx] = arr[0];
    
    for (int i = 1; i < N; i++) {
        //오름차순이라면
        if (dp[idx] < arr[i]) {
            dp[++idx] = arr[i];
        } else {
            int idx2 = lower_bound(dp, dp + idx, arr[i]) - dp;
            dp[idx2] = arr[i];
        }
    }
    return idx + 1;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    cout << LIS() << "\n";
    
    return 0;
}
