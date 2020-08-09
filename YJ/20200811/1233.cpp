//
//  1233.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/09.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int s1, s2, s3, max_bin = -2147000000;
vector<int> vec_s1, vec_s2, vec_s3;
vector<int> sum_chk;

void DFS(int Lv, int sum) {
    if (Lv == 3) {
        sum_chk[sum] += 1;
        if (sum_chk[sum] > max_bin) max_bin = sum_chk[sum];
    } else {
        if (Lv == 0) {
            for (int i = 0; i < vec_s1.size(); i ++) {
                DFS(Lv + 1, sum + vec_s1[i]);
            }
        } else if (Lv == 1) {
            for (int i = 0; i < vec_s2.size(); i ++) {
                DFS(Lv + 1, sum + vec_s2[i]);
            }
        } else {
            for (int i = 0; i < vec_s3.size(); i ++) {
                DFS(Lv + 1, sum + vec_s3[i]);
            }
        }
    }
    
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s1 >> s2 >> s3;
    
    sum_chk.resize(s1 + s2 + s3 + 1, 0);
    
    for (int i = 1; i <= s1; i ++) {
        vec_s1.push_back(i);
    }
    for (int i = 1; i <= s2; i ++) {
        vec_s2.push_back(i);
    }
    for (int i = 1; i <= s3; i ++) {
        vec_s3.push_back(i);
    }
    
    DFS(0, 0);
    
    for (int i = 1; i <= s1 + s2 + s3; i ++) {
        if (sum_chk[i] == max_bin) {
            cout << i << '\n';
            break;
        }
    }
    
    return 0;
}
