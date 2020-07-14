#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string arr[1001];
    int R,C;
    cin>>R>>C;
    map<string, int> m;
    
    for(int i=0; i<R; i++){
        cin>>arr[i];
    }
    
    int first =0;
    int last = R-1;
    int mid = 0;
    
    bool result_check;
    while(first<=last){
        bool check = true;
        mid = (first + last) / 2;
        for(int i=0; i<C; i++){
            string temp = "";
            for(int j=mid; j<R; j++){
                temp+= arr[j][i];
            }
            if(m[temp]){
                check = false;
                break;
            }
            m[temp]++;
        }
        if(check){
            first = mid + 1;
        }else{
            last = mid - 1;
        }
        result_check=check;
        m.clear();
    }
    if(result_check)cout<<mid;
    else cout<<mid-1;
    
    return 0;
}
