#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
bool visit[10000000];
bool chk[10];

bool is_prime(int num) {
    if (num <= 1)
        return false;
    for (int i = 2; i < num; i ++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

void DFS(int Cnt, string S, string Res)
{
    if(Res != "" && visit[stoi(Res)] == false)
    {
        int Num = stoi(Res);
        visit[Num] = true;
        if (is_prime(Num) == true) answer++;
    }
 
    for (int i = 0; i < S.length(); i++)
    {
        if (chk[i] == true) continue;
        chk[i] = true;
        DFS(Cnt + 1, S, Res + S[i]);
        chk[i] = false;
    }
}
 
int solution(string S)
{
    DFS(0, S, "");
    return answer;
}
