//
//  1969.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/16.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, result_num = 0;
    int head_num[51][4] = { 0 }; // A C G T
    string tmp, result;
    
    cin >> N >> M;
    for (int i = 0; i < N; i ++) {
        cin >> tmp;
        for (int j = 0; j < M; j ++) {
            switch(tmp[j]) {
                case 'T':
                    head_num[j][3] ++;
                    break;
                case 'A':
                    head_num[j][0] ++;
                    break;
                case 'C':
                    head_num[j][1] ++;
                    break;
                case 'G':
                    head_num[j][2] ++;
                    break;
            }
        }
    }
    
    for (int i = 0; i < M; i ++) {
        int tmp_max = 0;
        char tmp_char = ' ';
        for (int j = 0; j < 4; j ++) {
            if (head_num[i][j] > tmp_max) {
                tmp_max = head_num[i][j];
                if (j == 0) tmp_char = 'A';
                else if (j == 1) tmp_char = 'C';
                else if (j == 2) tmp_char = 'G';
                else tmp_char = 'T';
            }
        }
        result.push_back(tmp_char);
        result_num += (N - tmp_max);
    }
    
    cout << result << '\n' << result_num << '\n';
    
    return 0;
}
