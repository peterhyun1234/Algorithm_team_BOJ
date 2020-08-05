//
//  1182.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/04.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int N, S, tmp, cnt = 0;
deque<int> nums;

void DFS(int Lv, int sum) {
    if (Lv == N - 1) {
        if (sum == S) cnt ++;
    } else {
        DFS(Lv + 1, sum + nums[Lv + 1]);
        DFS(Lv + 1, sum);
    }
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> S;
    
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    
    while(N > 0) {
        DFS(0, nums.front());
        nums.push_back(nums.front());
        nums.pop_front();
        N --;
    }
    
    cout << cnt << '\n';
    
    return 0;
}
