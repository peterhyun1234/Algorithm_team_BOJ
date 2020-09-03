#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 0; i < puddles.size(); i ++) {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    for (int i = 2; i <= m; i ++) {
        if (dp[1][i] < 0)
            break;
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i ++) {
        if (dp[i][1] < 0)
            break;
        dp [i][1] = 1;
    }
    
    for (int i = 2; i <= n; i ++) {
        for (int j = 2; j <= m; j ++) {
            if (dp[i][j] < 0) continue;
            dp[i][j] = (dp[i-1][j]+ dp[i][j-1]) % 1000000007;
            
            if (dp[i-1][j] < 0 && dp[i][j-1] < 0) dp[i][j] = 0;
            else if (dp[i-1][j] < 0 || dp[i][j-1] < 0) dp[i][j] ++;
        }
    }
    
    return dp[n][m];
}
