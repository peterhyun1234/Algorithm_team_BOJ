//
//  1021.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/21.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> queue;
int sum = 0;

void move_left() {
    int tmp = queue.front();
    queue.pop_front();
    queue.push_back(tmp);
    sum ++;
    
    return ;
}

void move_right() {
    int tmp = queue.back();
    queue.pop_back();
    queue.push_front(tmp);
    sum ++;
    
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m, n;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        queue.push_back(i);
    }
    
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        int mid = (int(queue.size()) % 2) == 0 ? (int(queue.size()) / 2) - 1 : (int(queue.size()) / 2);
        int tmp_address = int(find(queue.begin(), queue.end(), tmp) - queue.begin());
        
        if (tmp_address <= mid) {
            if (tmp == queue.front()) {
                queue.pop_front();
                continue;
            }
            for (int j = 0; queue.front() != tmp; j++) {
                move_left();
            }
            queue.pop_front();
        } else {
            for (int j = 0; queue.front() != tmp; j++) {
                move_right();
            }
            queue.pop_front();
        }
    }
    
    cout << sum << '\n';
    
    return 0;
}
