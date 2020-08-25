// {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열
// {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

// 가장 긴 바이토닉 수열의 길이는?

// LIS + LDS로 풀어보자

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> a(n);
    vector<int> lis(n);
    vector<int> lds(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        lds[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[i] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
        }
    }

    int bitonic_max_len = lis[0] + lds[0] - 1;

    for (int i = 0; i < n; i++)
    {
        int curr_len = lis[i] + lds[i] - 1;
        bitonic_max_len = max(bitonic_max_len, curr_len);
    }

    cout << bitonic_max_len << "\n";
    
    return 0;
}