//
//  11047.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/19.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K, count = 0;
    cin >> N >> K;
    int coins[10];
    
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    
    for (int i = N - 1; i >= 0; i--) {
        if (coins[i] <= K) {
            while(true) {
                K -= coins[i];
                count ++;
                if (K < coins[i]) break;
            }
        }
    }
    
    cout << count << '\n';
    
    return 0;
}
