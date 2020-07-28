//
//  9663.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/28.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int board[15];
int cnt = 0;

bool is_valid(int i) {
    for (int j = 0; j < i; j++) {
        if(board[j] == board[i] || abs(board[i] - board[j]) == (i - j))
        return false;
    }
    return true;
}

void Queen(int i) {
    if (i == N) cnt += 1;
    else {
        for (int j = 0; j < N; j++) {
            board[i] = j;
            if (is_valid(i)) Queen(i + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    Queen(0);
    
    cout << cnt << '\n';
    
    return 0;
}
