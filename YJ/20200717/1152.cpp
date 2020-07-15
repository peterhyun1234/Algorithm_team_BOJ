//
//  1152.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/15.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int count = 1;
    string str;
    getline(cin, str);
    
    if (str[0] == ' ') {
        if (str.size() == 1) count --;
        for (int i = 1; i < str.size(); i++) {
            if (i == str.size() - 1 && str[i] == ' ') break;
            if (str[i] == ' ') count ++;
        }
    } else {
        for (int j = 0; j < str.size(); j++) {
            if (j == str.size() - 1 && str[j] == ' ') break;
            if (str[j] == ' ') count ++;
        }
    }
    
    cout << count << '\n';
    
    return 0;
}
