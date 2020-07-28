//
//  2075.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/27.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<>> pq;
    int num;
    cin >> num;
    
    for (int i = 0; i < num * num; i++) {
        int tmp;
        cin >> tmp;
        if (pq.size() < num) pq.push(tmp);
        else {
            pq.push(tmp);
            pq.pop();
        }
    }
    
    cout << pq.top() << '\n';
    
    return 0;
}

/*
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int> pq;
    int num;
    cin >> num;
    
    for (int i = 0; i < num * num; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    
    for (int i = 0; i < num - 1; i++) {
        pq.pop();
    }
    
    cout << pq.top() << '\n';
    
    return 0;
}
*/
