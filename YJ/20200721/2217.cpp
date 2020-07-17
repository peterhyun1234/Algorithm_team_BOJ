//
//  2217.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int arr[100000];
    int T, max = 0;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + T);
    max = arr[0] * T;
    
    for (int i = 1; i < T; i++) {
        if (arr[i] * (T - i) > max) max = arr[i] * (T - i);
    }
    
    cout << max << '\n';
    
    return 0;
}
