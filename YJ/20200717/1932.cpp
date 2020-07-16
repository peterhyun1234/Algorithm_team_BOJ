#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int arr[501][501];
    int dp[501][501];
    int T;
    cin >> T;
    cin.ignore();
    
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];
    
    for (int i = 1; i < T; i++) {
        dp[i][0] = arr[i][0] + dp[i - 1][0];
    }
    
    for (int i = 1; i < T; i++) {
        dp[i][i] = arr[i][i] + dp[i - 1][i - 1];
    }
    
    for (int i = 2; i < T; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = dp[i - 1][j - 1] > dp[i - 1][j] ? dp[i - 1][j - 1] : dp[i - 1][j];
            dp[i][j] += arr[i][j];
        }
    }
    
    int max = 0;
    for (int i = 0; i < T; i++) {
        if (dp[T - 1][i] > max) max = dp[T - 1][i];
    }
    
    cout << max << '\n';
    
    return 0;
}
