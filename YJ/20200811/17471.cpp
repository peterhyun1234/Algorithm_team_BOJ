//
//  17471.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/09.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, a, b, people_of_city[11], graph[11][11] = { 0 };
    
    cin >> N;
    for (int i = 1; i <= N; i ++) {
        cin >> people_of_city[i];
    }
    for (int i = 1; i <= N; i ++) {
        cin >> a;
        for (int j = 0; j < a; j ++) {
            cin >> b;
            graph[i][b] = 1;
        }
    }
    
    return 0;
}
