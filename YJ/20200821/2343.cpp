//
//  2343.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/18.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M, tmp, lft, rt, sum = 0, mid = 0, result, max_len = -2147000000;
vector<int> lessons;

int dvd_num(int size) {
    int cnt = 1, sum = 0;
    
    for (int i = 0; i < N; i ++ ) {
        if (sum + lessons[i] > size) {
            cnt ++;
            sum = lessons[i];
        } else {
            sum += lessons[i];
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        lessons.push_back(tmp);
        if (tmp > max_len) max_len = tmp;
        sum += tmp;
    }
    
    lft = max_len;
    rt = sum;
        
    while(lft <= rt) {
        mid = (lft + rt) / 2;
        
        if (dvd_num(mid) <= M) {
            result = mid;
            rt = mid - 1;
        } else {
            lft = mid + 1;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
