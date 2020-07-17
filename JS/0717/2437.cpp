
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    vector<int> weights;

    cin >>N;
    for(int i=0; i<N; i++){
        int num;
        cin >>num;
        weights.push_back(num);
    }
    sort(weights.begin(), weights.end());
    int min = 0;
    for(int i=0; i<N; i++){
        if(weights[i] > min+1)break;
        min += weights[i];
    }
    cout<<min+1;
    return 0;
}
