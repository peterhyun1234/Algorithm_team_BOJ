//
//  1759.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/04.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int l_size, int c_size, char ch_input[], char ch_result[], int node, int cnt) {
    // 재귀함수 종료 조건
    if (cnt == l_size) {
        int vowel = 0, consonant = 0;
        for (int i = 0; i < l_size; i++) {
            if (ch_result[i] == 'a' || ch_result[i] == 'e' || ch_result[i] == 'i' || ch_result[i] == 'o' || ch_result[i] == 'u')
                vowel++;
            else consonant++;
        }

        // 자음, 모음이 기준치를 넘지 못했을 때, 그때의 경우의수는 출력하지 않음.
        if (!(vowel >= 1 && consonant >= 2)) return;

        // 츨력단
        for (int i = 0; i < l_size; i++) {
            cout << ch_result[i];
        }
        cout << "\n";
        return;
    }

    // 탐색
    for (int i = node; i < c_size; i++) {
        ch_result[cnt] = ch_input[i];
        dfs(l_size, c_size, ch_input, ch_result, i + 1, cnt + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l_size, c_size;
    char ch_input[15], ch_result[15];


    // 입력단
    cin >> l_size >> c_size;
    for (int i = 0; i < c_size; i++)
        cin >> ch_input[i];
    
    // 알파벳 순으로 입력 정렬
    sort(ch_input, ch_input + c_size);

    // DFS
    dfs(l_size, c_size, ch_input, ch_result, 0, 0);

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int L, C;
char tmp;
string st;
vector<char> vowel;
vector<char> consonont;
vector<char> alphabets;
vector<int> chk;

void DFS(int idx, string str) {
    cout << idx << ' ' << str << ' ' << str.size() << '\n';
    if (str.size() > L) return ;
    if (str.size() == L) {
        cout << str << '\n';
        return ;
    }
    else {
        string tmp;
        tmp.push_back(alphabets[idx + 1]);
        chk[idx + 1] = 1;
        DFS(idx + 1, str + tmp);
        chk[idx + 1] = 0;
        DFS(idx + 1, str);
    }
    
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> L >> C;
    for (int i = 0; i < C; i ++) {
        cin >> tmp;
        alphabets.push_back(tmp);
        if (tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u')
            vowel.push_back(tmp);
        else
            consonont.push_back(tmp);
    }
    
    chk.resize(C);
    sort(alphabets.begin(), alphabets.end());
    
    
    for (int i = 0; i < C; i ++) {
        cout << alphabets[i] << ' ';
    }
    
    
    for (int i = 0; i < vowel.size(); i ++) {
        int iidx = 0;
        for (int j = 0; j < alphabets.size(); j ++) {
            if (vowel[i] == alphabets[j]) {
                iidx = j;
                break;
            }
        }
        st.push_back(vowel[i]);
        DFS(iidx, st);
    }
    
    return 0;
}
*/
