#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    int d[301][2];
    cin >> n;
    
    vector<int> stairs;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        stairs.push_back(num);
    }
    
    d[0][0] = stairs[0];
    d[1][0] = stairs[1];
    d[1][1] = stairs[0] + stairs[1];
    
    for(int i=2; i<n; i++){
        d[i][0] = max(d[i-2][0] + stairs[i], d[i-2][1] + stairs[i]);
        d[i][1] = (d[i-1][0] + stairs[i]);
    }
    cout<<max(d[n-1][0], d[n-1][1]);
    
}
