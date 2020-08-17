//
//  12100.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int N, map[21][21], store_map[21][21], max_val = -2147000000;
char dir[4] = {'u', 'd', 'r', 'l'};

void up() {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (map[i][j] == 0) {
                for (int k = i + 1; k < N; k ++) {
                    if (map[k][j] != 0) {
                        bool flag = false;
                        for (int m = k + 1; m < N; m ++) {
                            if (map[m][j] == 0) continue;
                            else {
                                if (map[m][j] == map[k][j]) {
                                    map[i][j] = map[k][j] * 2;
                                    map[k][j] = 0;
                                    map[m][j] = 0;
                                    flag = true;
                                    break;
                                } else break;
                            }
                        }
                        if (flag) break;
                        map[i][j] = map[k][j];
                        map[k][j] = 0;
                        break;
                    }
                }
            } else {
                for (int k = i + 1; k < N; k ++) {
                    if (map[k][j] == 0) continue;
                    else {
                        if (map[k][j] == map[i][j]) {
                            map[i][j] *= 2;
                            map[k][j] = 0;
                            break;
                        } else break;
                    }
                }
            }
        }
    }
}

void down() {
    for (int i = N - 1; i >= 0; i --) {
        for (int j = N - 1; j >= 0; j --) {
            if (map[i][j] == 0) {
                for (int k = i - 1; k >= 0; k --) {
                    if (map[k][j] != 0) {
                        bool flag = false;
                        for (int m = k - 1; m >= 0; m --) {
                            if (map[m][j] == 0) continue;
                            else {
                                if (map[m][j] == map[k][j]) {
                                    map[i][j] = map[k][j] * 2;
                                    map[k][j] = 0;
                                    map[m][j] = 0;
                                    flag = true;
                                    break;
                                } else break;
                            }
                        }
                        if (flag) break;
                        map[i][j] = map[k][j];
                        map[k][j] = 0;
                        break;
                    }
                }
            } else {
                for (int k = i - 1; k >= 0; k --) {
                    if (map[k][j] == 0) continue;
                    else {
                        if (map[k][j] == map[i][j]) {
                            map[i][j] *= 2;
                            map[k][j] = 0;
                            break;
                        } else break;
                    }
                }
            }
        }
    }
}

void right() {
    for (int i = N - 1; i >= 0; i --) {
        for (int j = N - 1; j >= 0; j --) {
            if (map[i][j] == 0) {
                for (int k = j - 1; k >= 0; k --) {
                    if (map[i][k] != 0) {
                        bool flag = false;
                        for (int m = k - 1; m >= 0; m --) {
                            if (map[i][m] == 0) continue;
                            else {
                                if (map[i][m] == map[i][k]) {
                                    map[i][j] = map[i][k] * 2;
                                    map[i][k] = 0;
                                    map[i][m] = 0;
                                    flag = true;
                                    break;
                                } else break;
                            }
                        }
                        if (flag) break;
                        map[i][j] = map[i][k];
                        map[i][k] = 0;
                        break;
                    }
                }
            } else {
                for (int k = j - 1; k >= 0; k --) {
                    if (map[i][k] == 0) continue;
                    else {
                        if (map[i][k] == map[i][j]) {
                            map[i][j] *= 2;
                            map[i][k] = 0;
                            break;
                        } else break;
                    }
                }
            }
        }
    }
}

void left () {
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (map[i][j] == 0) {
                for (int k = j + 1; k < N; k ++) {
                    if (map[i][k] != 0) {
                        bool flag = false;
                        for (int m = k + 1; m < N; m ++) {
                            if (map[i][m] == 0) continue;
                            else {
                                if (map[i][m] == map[i][k]) {
                                    map[i][j] = map[i][k] * 2;
                                    map[i][k] = 0;
                                    map[i][m] = 0;
                                    flag = true;
                                    break;
                                } else break;
                            }
                        }
                        if (flag) break;
                        map[i][j] = map[i][k];
                        map[i][k] = 0;
                        break;
                    }
                }
            } else {
                for (int k = j + 1; k < N; k ++) {
                    if (map[i][k] == 0) continue;
                    else {
                        if (map[i][k] == map[i][j]) {
                            map[i][j] *= 2;
                            map[i][k] = 0;
                            break;
                        }
                        else break;
                    }
                }
            }
        }
    }
}

void DFS(int Level, string str) {
    if (Level == 5) {
        for (int i = 0; i < 5; i ++) {
            switch(str[i]) {
                case 'u':
                    up();
                    break;
                case 'd':
                    down();
                    break;
                case 'r':
                    right();
                    break;
                case 'l':
                    left();
                    break;
            }
        }
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                if (map[i][j] > max_val) {
                    max_val = map[i][j];
                }
            }
        }
        
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {
                map[i][j] = store_map[i][j];
            }
        }
    
        return ;
    }
    
    for (int i = 0; i < 4; i ++) {
        str.push_back(dir[i]);
        DFS(Level + 1, str);
        str.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> map[i][j];
            store_map[i][j] = map[i][j];
        }
    }
    
    DFS(0, "");
    
    /*
    cout << '\n';
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    */
    
    cout << max_val << '\n';
    return 0;
}
