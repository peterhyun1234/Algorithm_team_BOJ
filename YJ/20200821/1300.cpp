//
//  1300.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/20.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int N, K;

int min (int a, int b) {
    return a < b ? a : b;
}

int front_count(int num) {
    int cnt = 0;
    
    for (int i = 1; i <= N; i ++) {
        cnt += min(num / i, N);
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int lft, rt, mid = 0, result = 0;
    cin >> N >> K;
    
    lft = 1;
    rt = K;
    
    while(lft <= rt) {
        mid = (lft + rt) / 2;
        
        if (front_count(mid) < K) {
            lft = mid + 1;
        } else {
            result = mid;
            rt = mid - 1;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
