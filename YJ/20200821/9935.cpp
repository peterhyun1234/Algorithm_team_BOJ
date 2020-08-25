//
//  9935.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/18.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int MAX = 1000001;
string s, bomb;
char result[MAX];

int main(void) {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> bomb;
    cin.ignore();
    
    int idx = 0;
    
    for (int i = 0; i < s.length(); i++) {
        result[idx++] = s[i];
        //폭탄으로 추정되는 부분 문자열 발견
        if (result[idx - 1] == bomb[bomb.length() - 1]) {
            //기저 사례
            if (idx - bomb.length() < 0)
                continue;
            //폭탄 여부 파악
            bool detected = true;
            for(int j = 0; j < bomb.length(); j++)
                if (result[idx - j - 1] != bomb[bomb.length() - j - 1]) {
                    detected = false;
                    break;
                }
            
            //폭탄 제거
            if (detected)
                idx -= bomb.length();
        }
    }
        
    if (!idx)
        cout << "FRULA\n";
    else {
        for (int i = 0; i < idx; i++)
            cout << result[i];
        cout << "\n";
    }
    
    return 0;
}

/*
 #include <iostream>
 #include <string>
 #include <vector>
 
 using namespace std;
 
 int main() {
 ios::sync_with_stdio(false);
 cin.tie(0);
 cout.tie(0);
 
 string str;
 string bomb;
 vector<char> answer;
 
 cin >> str >> bomb;
 
 if (str.size() < bomb.size()) {
 cout << "FRULA" << '\n';
 return 0;
 }
 
 for (int i = 0; i < str.size(); i ++) {
 if (str[i] != bomb[bomb.size() - 1]) {
 answer.push_back(str[i]);
 } else {
 if (answer.empty()) {
 answer.push_back(str[i]);
 continue;
 }
 string tmp_str;
 bool flag = false;
 for (int j = int(bomb.size()) - 2; j >= 0; j --) {
 char tmp = answer.back();
 if (tmp == bomb[j]) {
 answer.pop_back();
 tmp_str.push_back(tmp);
 }
 else {
 tmp_str.push_back(str[i]);
 flag = true;
 break;
 }
 }
 if (flag) {
 for (int m = 0; m < tmp_str.size(); m ++) {
 answer.push_back(tmp_str[m]);
 }
 }
 }
 }
 
 if (answer.size() == 0) {
 cout << "FRULA" << '\n';
 return 0;
 }
 
 for (int i = 0; i < answer.size(); i ++) {
 cout << answer[i];
 }
 cout << '\n';
 
 return 0;
 }
 */
