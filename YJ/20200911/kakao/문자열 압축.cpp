#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 2000, st_len = s.length();

    if (st_len == 1) return 1;

    for (int k = 1; k <= st_len / 2 + 1; k ++) {
        string ans = "";

        string tmp = s.substr(0, k);
        int cnt = 0;

        for (int i = k; i < st_len; i = i + k) {
            if (tmp == s.substr(i, k)) cnt ++;
            else {
                if (cnt >= 1)
                    ans += to_string(cnt + 1);
                cnt = 0;
                ans += tmp;
                tmp = s.substr(i, k);
            }
            if (i + k >= st_len) {
                if (cnt >= 1)
                    ans += to_string(cnt + 1);
                ans += tmp;
                tmp = s.substr(i, k);
            }
        }

        if (ans.length() < answer) {
            answer = ans.length();
        }
    }

    return answer;
}
