#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    
    vector<int> ropes;
    int num;
    for(int i = 0; i< N; i++){
        cin >> num;
        ropes.push_back(num);
    }
    sort(ropes.begin(), ropes.end());
    
    int max = -1;
    for(int i = 0 ; i < N ; i++){
        int temp = ropes[i] * int(ropes.size() - i);
        if(max<temp) max = temp;
    }
    
    cout<<max;
    
    return 0;
}
