//
//  11053.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/15.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int input[1001];
    int size;
    cin >> size;
    vector<int> maxLength;
    
    for (int i = 0; i < size; i++) {
        cin >> input[i];
        
        if (i == 0) maxLength.push_back(input[i]);
        else {
            for (int j = int(maxLength.size()) - 1; j >= 0; j--) {
                if (input[i] > maxLength.back()) maxLength.push_back(input[i]);
                else if (input[i] < maxLength[j] && input[i] > maxLength[j - 1]){
                    maxLength[j] = input[i];
                }
            }
        }
    }
    
    cout << maxLength.size() << '\n';
    
    return 0;
}
