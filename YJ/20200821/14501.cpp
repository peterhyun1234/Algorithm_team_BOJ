//
//  14501.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/18.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, a, b;
    int dp[16] = { 0 };
    
    cin >> N;
    vector<pair<int, int> > counsel(N + 1);
    vector<int> chk(N + 1, 0);
    
    for (int i = 1; i <= N ; i ++) {
        cin >> a >> b;
        counsel[i] = {a, b};
    }
    
    dp[1] = counsel[1].first == 1 ? counsel[1].second : 0;
    for (int i = 2; i <= N; i ++) {
        if (dp[i - 1] == 0) {
            int tmp_max = -2147000000;
            for (int j = 1; j <= i; j ++) {
                if (counsel[j].first == (i - j + 1)) tmp_max = max(tmp_max, counsel[j].second);
            }
            if (tmp_max == -2147000000) tmp_max = 0;
            dp[i] = tmp_max;
        } else {
            if (counsel[i].first == 1) dp[i] = counsel[i].second;
            else dp[i] = dp[i - 1];
        }
    }
    
    for (int i = 1; i <= N; i ++) {
        cout << dp[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
