// 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, s;
int numbers[20];
int degree_of_s = 0;

void dfs(int idx, int sum)
{
    sum += numbers[idx]; 

    if (idx >= n )
        return;

    if (sum == s)
        degree_of_s++;

    dfs(idx + 1, sum - numbers[idx]);
    dfs(idx + 1, sum);
}


int main(void)
{
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> numbers[i];

    dfs(0, 0);

    cout << degree_of_s << "\n";
    return 0;
}
