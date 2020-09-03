#include <iostream>
#include <string>
#include <vector>

using namespace std;

int max_val(int a, int b) {
    return a > b ? a : b;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0, dp[500][500] = { 0 }, tmp = -2147000000;
    
    dp[0][0] = triangle[0][0];
    
    for (int i = 1; i < triangle.size(); i ++) {
        dp[i][0] = triangle[i][0] + dp[i - 1][0];
        dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
    }
    
    for (int i = 2; i < triangle.size(); i ++) {
        for (int j = 1; j < (triangle[i].size() - 1); j ++) {
            dp[i][j] = max_val(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }
    
    for (int i = 0; i < triangle[triangle.size() - 1].size(); i ++) {
        tmp = max_val(tmp, dp[triangle.size() - 1][i]);
    }
    
    answer = tmp;
    
    return answer;
}
