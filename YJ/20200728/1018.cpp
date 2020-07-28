//
//  1018.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/27.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int WB_num(int x, int y, string board[]) {
    int cnt = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(board[x + i][y + j] != WB[i][j]) cnt ++;
        }
    }
    
    return cnt;
}

int BW_num(int x, int y, string board[]) {
    int cnt = 0;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(board[x + i][y + j] != BW[i][j]) cnt ++;
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int row, column, min_val = 2500;
    string board[50];
    
    cin >> row >> column;
    
    for (int i = 0; i < row; i++) {
        cin >> board[i];
    }
    
    for (int i = 0; i + 8 <= row; i++) {
        for (int j = 0; j + 8 <= column; j++) {
            int tmp;
            tmp = min(WB_num(i, j, board), BW_num(i, j, board));
            if (tmp < min_val) min_val = tmp;
        }
    }
    
    cout << min_val << '\n';
    
    return 0;
}
