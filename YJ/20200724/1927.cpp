//
//  1927.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/21.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int oper;
        cin >> oper;
        
        if (oper == 0) {
            if (pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else pq.push(oper);
    }
    return 0;
}
