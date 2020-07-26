// 퀸은 상하좌우, 대각선 공격 가능
// 크기가 N × N인 체스판 위에 퀸 N개
// Output은 퀸을 놓는 방법의 수
// 백트래킹 + prunnig, promising? 뭐가 맞는 건지는 모르겠지만;;


#include <iostream>
#include <vector>

using namespace std;

int n;
int col[15];
int degree_of_metheds = 0;

bool pruning(int i)
{
    for (int j = 0; j < i; j++)
    {
        if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
            return false;
    }
    return true;
}
void back_tracking(int i)
{
    if (i == n) {
        degree_of_metheds += 1;
        /*for (int a = 0; a < N; a++)
            cout << col[a] << " ";
        cout << "\n";*/
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            col[i] = j;
            if (pruning(i))
                back_tracking(i + 1);
        }
    }
}

int main()
{
    cin >> n;

    back_tracking(0);

    cout << degree_of_metheds << "\n";

    return 0;
}