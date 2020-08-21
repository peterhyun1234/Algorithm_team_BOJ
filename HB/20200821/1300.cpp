// 세준이는 크기가 N×N인 배열 A
// 배열에 들어있는 수 A[i][j] = i×j
// 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]

// 이것도 시간초과 조심해서 해아함! 
// 뭔가 DP문제 같긴한데...
// 이분탐색 문제인가?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int left = 1;
    int right = k;

    while(left <= right){
        int mid = left + (right - left) /2;
        int min_cnt = 0;

        for(int i = 1; i <= n; i++){
            min_cnt += min(mid/i, n);
        }

        if(min_cnt >= k){
            right = mid - 1;
        }else{
            left = mid + 1;
        }

    }

    cout << left << "\n";

    return 0;
}