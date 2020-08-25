//
//  1431.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/16.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct guitar {
    int size, sum;
    string str;
    guitar(int a, int b, string tmp) {
        size = a;
        sum = b;
        str = tmp;
    }
};

bool cmp (guitar a, guitar b) {
    if (a.size < b.size) return true;
    else if (a.size == b.size) {
        if (a.sum < b.sum) return true;
        else if (a.sum == b.sum) {
            for (int i = 0; i < a.size; i ++) {
                if (a.str[i] < b.str[i]) return true;
                else if (a.str[i] == b.str[i]) continue;
                else return false;
            }
            return false;
        }
        else return false;
    } else
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    string tmp;
    vector<guitar> Q;
    
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        int serial_size, serial_sum = 0;
        serial_size = int(tmp.size());
        for (int j = 0; j < serial_size; j ++) {
            if (tmp[j] - '0' >= 0 && tmp[j] - '0' <= 9) serial_sum += tmp[j] - '0';
        }
        Q.push_back(guitar(serial_size, serial_sum, tmp));
    }
    
    sort(Q.begin(), Q.end(), cmp);
    
    for (int i = 0; i < N; i ++) {
        cout << Q[i].str << '\n';
    }
    
    return 0;
}
