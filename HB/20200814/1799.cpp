// 체스에는 대각선 방향으로 움직일 수 있는 비숍(bishop)
// 비숍은 대각선 방향으로 움직여 O로 표시된 칸에 있는 다른 말
// 비숍이 놓일 수 없는 곳이 있다

// 비숍을 놓을 수 있는 곳에는 1, 비숍을 놓을 수 없는 곳에는 0
// 비숍의 최대 개수

// 저번에 풀었던 수도쿠랑 비슷함!
// 핵심은 체스판의 블랙과 화이트를 구분하는 것!

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int ans[2];
int chess[11][11];
int l[20];
int r[20];

void tracking(int row, int col, int count, int color)
{
    if (col >= N) {
        row++;
        if (col % 2 == 0) col = 1;
        else col = 0;
    }

    if (row >= N) {
        ans[color] = max(ans[color], count);
        return;
    }

    if (chess[row][col] && !l[col - row + N - 1] && !r[row + col])
    {
        l[col - row + N - 1] = 1; 
        r[row + col] = 1;
        tracking(row, col + 2, count + 1, color);
        l[col - row + N - 1] = 0;
        r[row + col] = 0;
    }
    tracking(row, col + 2, count, color);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> chess[i][j];
        }
    }

    tracking(0, 0, 0, 0);
    tracking(0, 1, 0, 1);

    cout << ans[0] + ans[1];

    return 0;
}
