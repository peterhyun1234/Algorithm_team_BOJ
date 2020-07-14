#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    
    queue<int> q;
    
    while(N--){
        int num;
        string command;
        cin>>command;
        if(command == "push"){
            cin >> num;
            q.push(num);
        }else if(command == "pop"){
            if(q.size() == 0){
                cout << -1;
            }else{
                num = q.front();
                cout << num;
                q.pop();
            }
            cout<<"\n";
        }else if(command == "size"){
            cout<<q.size();
            cout<<"\n";
        }else if(command == "empty"){
            cout<<q.empty();
            cout<<"\n";
        }else if(command == "front"){
            if(q.size()==0) cout<<-1;
            else cout<<q.front();
            cout<<"\n";
        }else if(command == "back"){
            if(q.size()==0)cout<< -1;
            else cout<<q.back();
            cout<<"\n";
        }
    }
    
    return 0;
    
}
