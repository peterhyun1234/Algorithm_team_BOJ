#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    int dp[1000] = {0, };
    cin >> n;

    dp[0]=1;
    dp[1]=1;
    
    for (int i=2; i<=n; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
        
    cout << dp[n]%10007;
    
    return 0;
}