
#include <iostream>
using namespace std;

int main(){
    long long d[10][101][1024] = {0,};
    int n;
    cin >> n;
    
    for(int i=1;i<10; i++){
        d[i][1][1<<i] = 1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<1024; k++){
                if(j == 0){
                    d[j][i][k | (1<<j)] += (d[j+1][i-1][k])%1000000000;
                }else if(j == 9){
                    d[j][i][k | (1<<j)] += (d[j-1][i-1][k])%1000000000;
                }else{
                    d[j][i][k | (1<<j)] += (d[j-1][i-1][k]+ d[j+1][i-1][k])%1000000000;
                }
            }
        }
    }
    
    long long result = 0;
    for(int i=0; i<10; i++){
        result =(result + d[i][n][1023]) %1000000000;
    }
    
    cout<<result<<endl;
    return 0;
}
