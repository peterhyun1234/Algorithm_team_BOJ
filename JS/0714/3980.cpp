#include <iostream>

using namespace std;

int arr[11][11]={0,};
bool visit[11] = {false,};
int maxValue;

void dfs(int v, int sum){
    if(v == 11){
        if(maxValue < sum){
            maxValue = sum;
        }
        return;
    }
    
    for(int i=0; i<11; i++){
        if(arr[v][i] > 0 && visit[i] == false){
            visit[i] = true;
            dfs(v+1, sum+arr[v][i]);
            visit[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int C;
    cin >>C;
    
    while(C--){
        maxValue = 0;
        
        for(int i=0; i<11; i++){
            for(int j=0; j<11;j++){
                cin>>arr[i][j];
            }
            visit[i] = false;
        }
        dfs(0,0);
        cout<<maxValue<<"\n";
    }
    
    return 0;
}
