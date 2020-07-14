
#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >>N;
    vector<int> histogram;
    
    for(int i=0; i<N; i++){
        int num;
        cin >>num;
        histogram.push_back(num);
    }
    
    int max = 0;
    for(int i=0; i<N; i++){
        int sum=0;
        if(histogram[i] == 0)continue;
        for(int j=i+1; j<N; j++){
            if(histogram[i] <=histogram[j]){
                sum+=histogram[i];
            }else break;
        }
        if(i>0){
            for(int j=i-1; j>=0; j--){
                if(histogram[i] <=histogram[j]){
                    sum+=histogram[i];
                }else break;
            }
        }
        sum+=histogram[i];
        if(max<sum)max=sum;
    }
    
    cout<<max;
}
