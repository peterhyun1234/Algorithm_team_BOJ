//
//  2352.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/16.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;

    cin >> n;
    vector<int> ports(n);
    vector<int> answer;
    
    for (int i = 0; i < n; i ++) {
        cin >> ports[i];
    }
    
    answer.push_back(ports[0]);
    
    for (int i = 1; i < n; i ++) {
        if (ports[i] > answer.back()) answer.push_back(ports[i]);
        else {
            int l_bound = int(lower_bound(answer.begin(), answer.end(), ports[i]) - answer.begin());
            answer[l_bound] = ports[i];
        }
    }
    
    cout << answer.size() << '\n';
    
    return 0;
}
