//
//  10610.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    string Num;
    cin >> Num;
    
    int sum = 0;
    bool isContainZero = false;
    
    for (int i = 0; i < Num.size(); i++) {
        if (Num[i] == '0') isContainZero = true;
        sum += Num[i] - '0';
    }
    
    if (isContainZero && (sum % 3 == 0)) {
        sort(Num.begin(), Num.end(), greater<int>());
        cout << Num << '\n';
    } else cout << -1 << '\n';
    
    return 0;
}
