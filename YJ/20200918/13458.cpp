//
//  13458.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/09/11.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, B, C, tmp;
    long long answer = 0;
    vector<int> A;
    
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        A.push_back(tmp);
    }
    cin >> B >> C;
    
    for (int i = 0; i < A.size(); i ++) {
        A[i] -= B;
        answer ++;
        
        if (A[i] > 0) {
            if (A[i] % C == 0)
                answer += (A[i] / C);
            else
                answer += (A[i] / C) + 1;
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}
