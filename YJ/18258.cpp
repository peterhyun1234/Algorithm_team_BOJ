//
//  18258.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/12.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    deque<int> dq;
    
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "push") {
            int number;
            cin >> number;
            dq.push_back(number);
        } else if (operation == "pop") {
            if (dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        } else if (operation == "size") {
            cout << dq.size() << '\n';
        } else if (operation == "empty") {
            if (dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (operation == "front") {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        } else if (operation == "back") {
            if (dq.empty()) cout << -1 << '\n';
            else cout << dq.back() <<'\n';
        }
    }
    
    return 0;
}

