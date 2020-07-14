//
//  1874.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/13.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num;
    cin >> num;
        
    vector<char> stk; // +, - 를 저장할 벡터
    deque<int> input; // 입력을 저장할 덱
    stack<int> numStack; // 1부터 n까지의 수를 저장, 제거할 스택
    
    for (int i = 0; i < num; i++) { // 사용자로부터 숫자 입력받음
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    
    for (int j = 1; j <= num; j++) { // 1 ~ n 까지 숫자를 스택에 push
        numStack.push(j);
        stk.push_back('+');
        
        for(int l = 0; !numStack.empty(); l++) { // 각 숫자를 일단 스택에 넣은 후
            if (numStack.top() == input.front()) { // 입력받은 값의 front와 numStack의 top이 같으면 pop
                numStack.pop();
                stk.push_back('-');
                input.pop_front();
            }
            else break; // 같지 않으면 반복분 해제
        }
        
    }
    
    if (stk.size() == num * 2){ // +와 -의 갯수의 합은 항상 입력받은 수 * 2가 돼야 한다.
        for (int k = 0; k < stk.size(); k++) {
            cout << stk[k] << '\n';
        }
    } else cout << "NO" << '\n';
    
    return 0;
}
