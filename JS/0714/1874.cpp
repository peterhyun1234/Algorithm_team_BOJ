#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    stack<int> s;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int temp;
        cin >>temp;
        arr.push_back(temp);
    }
    
    int index = 0;
    
    int number=1;
//    string answer="";
    vector<char> answer;
    bool check = true;
    while(true){
        s.push(number);
        number++;
//        cout<<'+'<<"\n";
        answer.push_back('+');
        if(number-n>n){
            check = false;
            break;
        }
        while(arr[index] == s.top()){
            s.pop();
//            cout<<'-'<<"\n";
            answer.push_back('-');
            index++;
            if(s.empty())break;
        }
        if(index == n)break;
    }
    if(check){
        for (int i = 0; i < answer.size(); i++) printf("%c\n", answer[i]);
    }else{
        cout<<"NO"<<"\n";
    }
    
    return 0;
}
