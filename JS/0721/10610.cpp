
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string n;
    cin >> n;
    
    int sum = 0;
    bool check = false;
    int index = 0;
    for(int i =0 ; i<n.length(); i++){
        int temp = n[i] - '0';
        sum +=temp;
        if(n[i] == '0') {
            check = true;
            index = i;
        }
    }
    if(sum %3 != 0 || !check){
        cout<< -1;
        return 0;
    }

    int arrays[10] = {0,};
    for(int i=0; i<n.length(); i++){
        arrays[n[i] - '0']++;
    }
    
    string result = "";
    for(int k=9; k>=0; k--){
        for(int x=0; x<arrays[k]; x++){
            result+=(k+'0');
        }
    }
    cout<<result;
}
