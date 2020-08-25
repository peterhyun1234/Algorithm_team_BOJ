//
//  2892.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    string tmp;
    string answer;
    cin >> N;
    
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        int hex = stoi(tmp, 0, 16);
        
        if (hex >= 64 && hex <= 95) {
            answer.push_back('-');
        } else {
            answer.push_back('.');
        }
    }
    
    for (int i = 0; i < N; i ++) {
        cout << answer[i];
    }
    cout << '\n';
    
    return 0;
}
