//
//  2798.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/24.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, cards[100];
    vector<int> max_values;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> cards[i];
    }
    
    sort(cards, cards + N, greater<>());
    
    for (int i = 0; i < N - 2; i++) {
        if (cards[i] >= M) continue;
        for (int j = i + 1; j < N - 1; j++) {
            if (cards[i] + cards[j] >= M) continue;
            for (int k = j + 1; k < N; k++) {
                if (cards[i] + cards[j] + cards[k] > M) continue;
                max_values.push_back(cards[i] + cards[j] + cards[k]);
            }
        }
    }
    
    sort(max_values.begin(), max_values.end(), greater<>());
    
    cout << max_values.front() << '\n';
    
    return 0;
}
