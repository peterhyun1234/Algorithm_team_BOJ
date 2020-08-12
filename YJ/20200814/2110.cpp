//
//  2110.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/11.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, tmp, mid, lt = 1, rt = -2147000000, result = 0;
vector<int> houses;

int house_num_share_machine(int dist) {
    int share_machine_pos = houses[0], cnt = 1;
    
    for (int i = 1; i < N; i ++) {
        if (houses[i] - share_machine_pos >= dist) {
            share_machine_pos = houses[i];
            cnt ++;
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> C;
    
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        houses.push_back(tmp);
        if (tmp > rt) rt = tmp;
    }
    
    sort(houses.begin(), houses.end());
    
    while(lt <= rt) {
        mid = (lt + rt) / 2;
        
        if (house_num_share_machine(mid) >= C) {
            lt = mid + 1;
            result = mid;
        } else {
            rt = mid - 1;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}

