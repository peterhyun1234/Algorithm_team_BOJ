//
//  1931.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/20.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> meetings(100001);
int T, result = 1;
int endTime = 0;

bool cmp(const pair<int, int> &A, const pair<int, int> &B) {
    if (A.second < B.second) return true;
    else if (A.second == B.second) return A.first < B.first;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> T;
    meetings.resize(T);
    
    for (int i = 0; i < T; i++) {
        int start, end;
        cin >> start >> end;
        meetings[i] = make_pair(start, end);
    }
    
    sort(meetings.begin(), meetings.end(), cmp);
    endTime = meetings[0].second;
    
    for (int i = 1; i < T; i++) {
        if (endTime <= meetings[i].first) {
            endTime = meetings[i].second;
            result ++;
        }
    }
    
    cout << result << '\n';
    
    return 0;
}
