//
//  2696.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/22.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int len;
        vector<int> mediums;
        
        cin >> len;
        vector<int> input_arr(len);
        
        for (int j = 0; j < len; j++) {
            int tmp;
            cin >> tmp;
                        
            // 맨 처음에는 그냥 input배열에 넣고 중앙값도 들어온 값 그대로 저장
            if (j == 0) {
                input_arr[j] = tmp;
                mediums.push_back(tmp);
                continue;
            }
            
            // 처음 값이 아니면 일단 정렬된 input_arr값의 맨 마지막 보다 크다면 input배열에 넣는다
            if (tmp > input_arr[j-1]) {
                input_arr[j] = tmp;
            } else { // input_arr값의 맨 마지막보다 작다면 lower_bound로 위치를 찾아서 삽입한다.
                int idx = int(lower_bound(input_arr.begin(), input_arr.begin() + j, tmp) - input_arr.begin());
                
                if (idx == 0) {
                    for (int k = j; k >= 1; k--) {
                        input_arr[k] = input_arr[k - 1];
                    }
                    input_arr[0] = tmp;
                } else {
                    for (int k = j + 1; k >= idx + 1; k--) {
                        input_arr[k] = input_arr[k - 1];
                    }
                    input_arr[idx] = tmp;
                }
            }
            
            // 입력값을 input 배열의 알맞은 위치에 넣고난 후 mid값을 구하여 저장, 출력한다.
            if (j % 2 == 0) {
                int mid_idx = (j + 1) / 2;
                mediums.push_back(input_arr[mid_idx]);
            }
        }
        
        int mid_count = (len % 2) == 0 ? len / 2: len / 2 + 1;
        cout << mid_count << '\n';
        // 중앙값 배열 출력
        for (int l = 0; l < mid_count; l++) {
            cout << mediums[l] << ' ';
            if (l % 10 == 9) cout << '\n';
        }
    }
    
    return 0 ;
}
