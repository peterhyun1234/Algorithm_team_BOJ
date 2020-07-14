//
//  9095.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/13.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int recur(int N, vector<int> cal) {
    if (N == 4) return cal[N - 2] + cal[N - 3] + cal[N - 4];
    else {
        for (int j = 0; j < N - 4; j++) {
            cal.push_back(cal[0 + j] + cal[1 + j] + cal[2 + j]);
        }
    }
    return cal[N - 2] + cal[N - 3] + cal[N - 4];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
    vector<int> cal;
    
    cal.push_back(1);
    cal.push_back(2);
    cal.push_back(4);
    
    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        
        if (tmp == 1) cout << 1 << '\n';
        else if (tmp == 2) cout << 2 << '\n';
        else if (tmp == 3) cout << 4 << '\n';
        else cout << recur(tmp, cal) << '\n';
    
    }
}
