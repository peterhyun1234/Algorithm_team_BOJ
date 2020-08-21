//
//  11054.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/19.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, result = -2147000000;
    int arr[1000], dp_l[1000], dp_r[1000];
    
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> arr[i];
    }
    
    dp_l[0] = 1;
    for (int i = 1; i < N; i ++) {
        int max_dp = 0;
        for (int j = 0; j < i; j ++) {
            if (arr[j] < arr[i])
                if (dp_l[j] > max_dp) max_dp = dp_l[j];
        }
        dp_l[i] = max_dp + 1;
    }
    
    dp_r[N - 1] = 1;
    for (int i = N - 2; i >= 0; i --) {
        int max_dp = 0;
        for (int j = N - 1; j > i; j --) {
            if (arr[j] < arr[i])
                if (dp_r[j] > max_dp) max_dp = dp_r[j];
        }
        dp_r[i] = max_dp + 1;
    }
    
    for (int i = 0; i < N; i ++) {
        if (dp_r[i] + dp_l[i] > result)
            result = dp_r[i] + dp_l[i];
    }
    
    cout << result - 1 << '\n';
    
    return 0;
}
