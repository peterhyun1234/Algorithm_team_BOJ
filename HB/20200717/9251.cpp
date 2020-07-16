// n^3까지 가능
// N*M으로 처리함
// 개념 도움: http://melonicedlatte.com/algorithm/2018/03/15/181550.html

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int dp[1001][1001]; // 이거 전역변수로하는 거랑 뭔 차이지?

int main() {

    string str1;
    string str2;


    cin >> str1 >> str2;

    int str1_len = str1.size();
    int str2_len = str2.size();

    for (int i = 1; i <= str2_len; i++) {
        for (int j = 1; j <= str1_len; j++) {
            if (str1.at(j - 1) == str2.at(i - 1)) {
                dp[i][j] += dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }

    cout << dp[str2_len][str1_len] << "\n";

    return 0;
}