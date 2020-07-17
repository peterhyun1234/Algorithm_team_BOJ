#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<int> A;
    vector<int> d(N, 0);
    
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        A.push_back(num);
    }
    
    for(int i=0; i<N; i++){
        d[i] = 1;
        for(int j=0; j<i; j++){
            if(A[i]>A[j]) d[i] = max(d[i], d[j]+1);
        }
    }
    int max = -1;
    for(int i=0; i<N; i++){
        if(max<d[i])max=d[i];
    }
    cout<<max;
}
