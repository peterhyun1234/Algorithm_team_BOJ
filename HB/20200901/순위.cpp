#include <string>
#include <vector>
#include <iostream>

using namespace std;

int game[101][101];
int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    for (int i = 0; i < results.size(); i++)
    {
        game[results[i][0]][results[i][1]] = 1;  // 승리
        game[results[i][1]][results[i][0]] = -1; // 패배
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (game[j][i] == 0)
            {
                continue;
            }
            for (int k = 1; k <= n; k++)
            {
                if (game[j][i] == game[i][k])
                {
                    game[j][k] = game[j][i];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int have_results = 0;
        for (int j = 1; j <= n; j++)
        {
            if (game[i][j] != 0 && i != j)
            {
                have_results ++;
            }
        }

        if (have_results == (n - 1))
        {
            answer++;
        }
    }
    return answer;
}