
#include <vector>
#include <iostream>
#include <string>
#include <deque>
#include <cstring>

using namespace std;

int main(){
    int T;
    cin >> T;
    
    while(T--){
        string p;
        string arr;
        int n;
        deque<int> dq;
        
        cin>>p;
        cin>>n;
        cin>>arr;
        
        string temp;
        for (int i = 0; i < arr.length(); i++){
             if (arr[i] == '[')
                 continue;
             else if ('0' <= arr[i] && arr[i] <= '9')
                 temp += arr[i];
             else if (arr[i] == ',' || arr[i] == ']')
             {
                 if (!temp.empty())
                 {
                      dq.push_back(stoi(temp));
                      temp.clear();
                 }
             }
        }
        
        bool is_front=true;
        bool iserror= false;
        for(char c:p){
            if(c == 'R'){
                is_front= !is_front;
            }else if(c == 'D'){
                if(dq.size() ==0){
                    cout<<"error";
                    iserror=true;
                    break;
                }
                
                if(is_front){
                    dq.pop_front();
                }else{
                    dq.pop_back();
                }
                
            }
        }
        if(!iserror){
            if(is_front){
                cout<<"[";
                deque<int>::iterator iter;
                for(iter = dq.begin(); iter!= dq.end(); iter++){
                    cout<< *iter;
                    if(iter!=dq.end()-1){
                       cout<<",";
                    }
                }
                cout<<"]";
            }else{
                cout<<"[";
                deque<int>::reverse_iterator rIter;
                for(rIter = dq.rbegin(); rIter!=dq.rend(); rIter++){
                    cout<< *rIter;
                    if(rIter!=dq.rend()-1){
                        cout<<",";
                    }
                }
                cout<<"]";
            }
        }
        cout<<"\n";
        
        
    }
    return 0;
}
