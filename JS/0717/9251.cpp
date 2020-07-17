#include <iostream>
using namespace std;

int d[1001][1001]={0,};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string first, second;
    cin >> first >> second;
    
    for(int i=1; i<=first.length(); i++){
        for(int j=1; j<=second.length(); j++){
            if(first[i-1] == second[j-1]){
                int temp = d[i-1][j-1]+1;
                d[i][j] = temp;
            }else{
            d[i][j]=max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    
    cout<<d[first.length()][second.length()];
    return 0;
}
