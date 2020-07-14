//
//  1016.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/13.
//  Copyright © 2020 황영준. All rights reserved.
//
/*
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int count = 0;
    int min, max;
    // bool arr[1000001] = {false, };
        
    cin >> min >> max;
    vector<bool> arr(max);
    
//    for (int i = 2; i*i <= max; i++) {
//        for (int j = 0; j <= max; j++) {
//            if (j == 0 || j == 1) continue;
//            if (!arr[j]) {
//                if (j % (i * i) == 0) {
//                    arr[j] = true;
//                    for (int m = 2; j * m < max; m++) {
//                        arr[j * m] = true;
//                    }
//                } else break;
//            }
//        }
//    }
    
    for (int i = 0; i <= max; i++) {
        if (i == 0 || i == 1 || i == 2 || i == 3) continue;
        if (!arr[i]) {
            for (int j = 2; j * j <=max; j++) {
                if (i < j * j) break;
                if (i % (j * j) == 0) {
                    arr[i] = true;
                    for (int m = 2; m * i < max; m++) {
                        arr[m * i] = true;
                    }
                    break;
                }
            }
        }
    }
    
    for (int k = min; k <= max; k++) {
        if(arr[k]) count++;
    }
    
    cout << (max - min + 1) - count << '\n';
    
    return 0;
}
*/
#include <iostream>
using namespace std;

bool isSqr[1000001];

int main() {
    long long min, max;
    cin >> min >> max;

    for (long long i = 2; i * i <= max; i++){
        long long start = min / (i * i);
        if (start * i * i != min) start++;
        for (long long j = start; i * i * j <= max; j++) {
            isSqr[i * i * j - min] = true;
        }
    }
    int count = 0;
    for (int i = 0; i < max - min + 1; i++) {
        if (!isSqr[i]) count++;
    }
    cout << count << endl;

    return 0;
}
