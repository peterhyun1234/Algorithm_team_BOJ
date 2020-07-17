//
//  4796.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/17.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int i = 1;
    
    while(true) {
        int L, P, V, result = 0;
        cin >> L >> P >> V;
        
        if (L == 0 && P == 0 && V == 0) break;
        
        result = (V / P) * L;
        if ((V % P) <= L) result += (V % P);
        else result += L;
        
        cout << "Case " << i << ": " << result << '\n';
        
        i++;
    }
    
    return 0;
}
