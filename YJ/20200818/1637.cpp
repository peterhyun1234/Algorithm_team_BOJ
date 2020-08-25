//
//  1637.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const long long INF = 1LL << 32;
const int MAX = 20010;
int n;
long long A[MAX], B[MAX], C[MAX];

long long func(long long mid) {
    long long ret = 0;
    for (int i = 0 ; i < n ; ++i) {
        if (mid >= A[i]) {
            ret += (min(mid, C[i]) - A[i]) / B[i] + 1;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n ; ++i) {
        cin >> A[i] >> C[i] >> B[i];
    }
    
    long long low = 0, high = INF;
    while (low < high) {
        long long mid = (low + high) / 2;
        if (func(mid) & 1) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    if (low == INF) {
        cout << "NOTHING" << '\n';
    } else {
        cout << low << ' ' << func(low) - func(low - 1) << '\n';
    }
}

/*
#include <iostream>
#include <set>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, a, b, c, max_res = 0, cnt = 0, result = 0;
    
    set<int> S;
    vector<int> arr;
    
    cin >> n;
    
    for (int i = 0; i < n; i ++) {
        cin >> a >> c >> b;
        
        int gob = 0;
        
        while ((a + gob * b) <= c) {
            arr.push_back(a + gob * b);
            cnt ++;
            
            bool insert_set = S.insert(a + gob * b).second;
            if (!insert_set) {
                S.erase(a + gob * b);
            }
            gob ++;
        }
    }
    
    if (S.empty()) {
        cout << "NOTHING" << '\n';
        return 0;
    } else {
        for (auto i = S.begin(); i != S.end(); i ++) {
            cout << *i << ' ';
            max_res = *i;
        }
    }
    
    for (int i = 0; i < cnt; i ++) {
        if (arr[i] == max_res) result ++;
    }
    
    cout << result << '\n';
    
    return 0;
}
*/
