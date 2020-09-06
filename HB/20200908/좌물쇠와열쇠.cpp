#include <string>
#include <vector>
using namespace std;

int keysize, locksize, boardsize;

void rotateKey(vector<vector<int>> &key)
{

    vector<vector<int>> tmp(keysize, vector<int>(keysize));

    for (int j = keysize - 1; j >= 0; j--)
    {
        for (int i = 0; i < keysize; i++)
        {
            tmp[i][j] = key[keysize - j - 1][i];
        }
    }

    key = tmp;
}

bool putKey(int x, int y, vector<vector<int>> key, vector<vector<int>> board)
{
    //(x, y)를 시작점으로 열쇠를 자물쇠에 맞춰본다.

    //key를 더한다
    for (int i = x; i < x + keysize; i++)
    {
        for (int j = y; j < y + keysize; j++)
        {
            board[i][j] += key[i - x][j - y];
        }
    }

    //좌물쇠 부분 확인
    for (int i = keysize - 1; i <= boardsize - keysize; i++)
    {
        for (int j = keysize - 1; j <= boardsize - keysize; j++)
        {
            if (board[i][j] == 1)
                continue;

            //1이 아니라면 바로 false를 리턴
            return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;

    keysize = key.size();
    locksize = lock.size();

    boardsize = locksize + (keysize - 1) * 2;
    vector<vector<int>> board(boardsize, vector<int>(boardsize, 0));

    //board에 lock을 미리 더해놓는다. (lock은 고정되어 있고 key를 움직일 것 이므로)
    for (int i = keysize - 1; i <= boardsize - keysize; i++)
    {
        for (int j = keysize - 1; j <= boardsize - keysize; j++)
        {
            board[i][j] = lock[i - keysize + 1][j - keysize + 1];
        }
    }

    //회전 방향 네번
    for (int r = 0; r < 4; r++)
    {

        for (int i = 0; i <= boardsize - keysize; i++)
        {
            for (int j = 0; j <= boardsize - keysize; j++)
            {

                //i,j 를 key의 시작칸으로 자물쇠 홈에 맞춰본다.
                if (putKey(i, j, key, board))
                {
                    answer = true;
                    return answer;
                }
            }
        }

        //key 시계방향으로 90도 회전
        rotateKey(key);
    }

    return answer;
}
