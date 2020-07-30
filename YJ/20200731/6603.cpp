//
//  6603.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/30.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int K, arr[20], chk[20];

void DFS(int idx, int cnt) {
    if (cnt == 6 || idx > K) {
        if (cnt == 6) {
            for (int i = 1; i <= K; i++) {
                if (chk[i] != 0) cout << arr[i] << ' ';
            }
            cout << '\n';
        }
        return ;
    } else {
        if (chk[idx + 1] == 0 && idx + 1 <= K) {
            chk[idx + 1] = 1;
            DFS(idx + 1, cnt + 1);
            chk[idx + 1] = 0;
            DFS(idx + 1, cnt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        
    while(true) {
        cin >> K;
        
        if(K == 0) break;
        else {
            for (int i = 1; i <= K; i++) {
                cin >> arr[i];
            }
            DFS(0, 0);
        }
        cout << '\n';
        
        memset(arr, 0, sizeof(arr));
        memset(chk, 0, sizeof(chk));
    }
    
    return 0;
}
