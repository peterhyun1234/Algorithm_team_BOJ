//
//  3079.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/12.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> test_times;

long long test_people_num(long long time) {
    long long cnt = 0;
    
    for (int i = 0; i < N; i ++) {
        cnt += time / test_times[i];
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int M;
    long long lt = 1, rt, mid, res = 0, tmp;
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        test_times.push_back(tmp);
    }
    
    sort(test_times.begin(), test_times.end());
    
    rt = test_times[N - 1] * M;
    
    while (lt <= rt) {
        mid = (lt + rt) / 2;
        
        if (test_people_num(mid) >= M) {
            rt = mid - 1;
            res = mid;
        } else {
            lt = mid + 1;
        }
    }
    
    cout << res << '\n';
    
    return 0;
}
