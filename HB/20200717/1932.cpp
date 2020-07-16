#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sum = 0;
    int n;
    cin >> n;

    vector<vector<int>> integer_square(n + 1, vector<int>(n + 1));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < i + 1; j++)
        {
            cin >> integer_square[i][j];
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < i + 1; j++)
        {
            integer_square[i][j] += max(integer_square[i - 1][j - 1], integer_square[i - 1][j]);
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (sum < integer_square[n][i])
            sum = integer_square[n][i];
        //cout << integer_square[n][i] << "\n";
    }

    cout << sum << "\n";

    return 0;
}