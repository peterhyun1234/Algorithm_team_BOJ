
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N, num;
    int arr[1000001] = {0,};
    int count = 0;
    cin>>N;
    while(N--){
        cin >> num;
        auto temp = lower_bound(arr, arr+count, num) - arr;
        if(temp == count){
            count++;
        }
        arr[temp] = num;
    }
    cout<<count;
}
