//
//  5585.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/15.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int money[6] = {500, 100, 50, 10, 5, 1};
    int pay;
    int count = 0;
    cin >> pay;
    int change = 1000 - pay;
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; change >= money[i]; j++) {
            if (change >= money[i]) {
                change -= money[i];
                count ++;
            }
        }
    }
    
    cout << count << '\n';
    
    return 0;
}
