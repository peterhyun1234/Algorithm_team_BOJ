#include <iostream>
#include <vector>

using namespace std;

int main(){
    int numbers[] = {1,2,3};
    int T;
    cin >> T;
    
    while(T--){
        int num;
        cin >>num;
        vector<int> d(num+1);
        d[0]=1;
        
        for(int i=1; i<=num; i++){
            for(int j=0; j<3; j++){
                if(i-numbers[j]>=0){
                    d[i] += d[i-numbers[j]];
                }
            }
        }
        cout<<d[num]<<endl;
    }
}
