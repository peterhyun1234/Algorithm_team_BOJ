//
//  1700.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/20.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K, pull = 0;
    int arr[101];
    cin >> N >> K;
    vector<int> gr;
    
    for (int i = 0; i < K; i ++) {
        cin >> arr[i];
    }
    
    gr.push_back(arr[0]);
    
    if (N == 1) {
        for (int i = 1; i < K; i++) {
            if (arr[i] != arr[i - 1]) pull ++;
        }
    } else {
        for (int i = 1; i < K; i++) {
            if (gr.size() < N && (find(gr.begin(), gr.end(), arr[i]) == gr.end())) gr.push_back(arr[i]);
            else {
                if (find(gr.begin(), gr.end(), arr[i]) == gr.end()) {
                    vector<int> isIn(N);
                    int limit = 0;
                    
                    for (int j = i + 1; j < K; j++) {
                        if (find(gr.begin(), gr.end(), arr[j]) != gr.end()) {
                            for (int m = 0; m < gr.size(); m++) {
                                if (gr[m] == arr[j] && isIn[m] != 1) {
                                    isIn[m] = 1;
                                    limit ++;
                                    break;
                                }
                            }
                            if (limit == gr.size() - 1) break;
                        }
                    }
                    
                    for (int k = 0; k < N; k++) {
                        if (isIn[k] != 1) {
                            gr[k] = arr[i];
                            pull ++;
                            break;
                        }
                    }
                }
            }
        }
    }
    
    cout << pull << '\n';
    
    return 0;
}
