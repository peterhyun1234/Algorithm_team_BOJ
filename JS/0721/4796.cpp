#include <iostream>

using namespace std;
int main(){
    int L,P,V;
    int T = 1;
    while(true){
        cin>>L>>P>>V;
        if(L==0&&P==0&&V==0)return 0;
        
        int p = V / P; // 2
        int l = V - p * P; // 20 - 16;
        if(l>L) l = L;
        int result = p * L + l;
        
        cout<<"Case "<<T++<<": "<<result<<"\n";
    }
}
