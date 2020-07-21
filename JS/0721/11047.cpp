#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    cin >>N>>K;
    
    vector<int> coins;
    for(int i =0; i<N; i++){
        int num;
        cin >> num;
        coins.push_back(num);
    }
    int count = 0;
    for(int i=int(coins.size())-1; i>=0; i--){
        if(K == 0) break;
        if(coins[i] <=K){
            int t = K / coins[i];
            K -= t*coins[i];
            count += t;
        }
            
    }
    
    cout<<count<<"\n";
    return 0;
}
