//
//  2580.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/28.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int sdoku[9][9];
int zero_cnt = 0;

bool chk_row(int r, int col) {
    int arr[10] = { 0 };
    int non_zero_cnt = 0, tmp = 0;
    for (int i = 0; i < 9; i++) {
        if (sdoku[r][i] != 0) arr[sdoku[r][i]] = 1;
    }
    for (int i = 1; i < 10; i++) {
        if (arr[i] == 0) {
            non_zero_cnt ++;
            tmp = i;
        }
    }
    if (non_zero_cnt == 1) {
        sdoku[r][col] = tmp;
        zero_cnt --;
        return true;
    }
    return false;
}

bool chk_column(int c, int row) {
    int arr[10] = { 0 };
    int non_zero_cnt = 0, tmp = 0;
    for (int i = 0; i < 9; i++) {
        if (sdoku[i][c] != 0) arr[sdoku[i][c]] = 1;
    }
    for (int i = 1; i < 10; i++) {
        if (arr[i] == 0) {
            non_zero_cnt ++;
            tmp = i;
        }
    }
    if (non_zero_cnt == 1) {
        sdoku[row][c] = tmp;
        zero_cnt --;
        return true;
    }
    return false;
}

bool chk_tri(int r, int c) {
    int arr[10] = { 0 };
    int non_zero_cnt = 0, tmp = 0;
    int row_tri = r / 3;
    int col_tri = c / 3;
        
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sdoku[i + row_tri * 3][j + col_tri * 3] != 0) arr[sdoku[i + row_tri * 3][j + col_tri * 3]] = 1;
        }
    }
    for (int i = 1; i < 10; i++) {
        if (arr[i] == 0) {
            non_zero_cnt ++;
            tmp = i;
        }
    }
    if (non_zero_cnt == 1) {
        sdoku[r][c] = tmp;
        zero_cnt --;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdoku[i][j];
            if (sdoku[i][j] == 0) zero_cnt ++;
        }
    }
    
    while(zero_cnt != 0) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (sdoku[row][col] != 0) continue;
                if (chk_row(row, col)) continue;
                if (chk_column(col, row)) continue;
                if (chk_tri(row, col)) continue;
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sdoku[i][j];
            if (j != 8) cout << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
