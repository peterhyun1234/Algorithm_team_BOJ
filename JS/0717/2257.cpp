#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string chemistry;
    cin >> chemistry;
    stack<int> chemi;
//    for(char c : chemistry){
//        chemi.push(c);
//    }
    int temp=0;
    chemi.push(0);
    for(int i=0; i<chemistry.length(); i++){
        char c = chemistry[i];
        
        if(c == 'H'){
            temp = 1;
            chemi.top()+=1;
        }else if(c == 'C'){
            temp=12;
            chemi.top()+=12;
        }else if(c == 'O'){
            temp=16;
            chemi.top()+=16;
        }else if(c == '('){
            chemi.push(0);
        }else if(c == ')'){
            temp = chemi.top();
            chemi.pop();
            chemi.top()+=temp;
        }else if(c > '1' && c<='9'){
            chemi.top()+= temp*(c-'1');
        }
    }
    cout<<chemi.top();
    

    return 0;
}
