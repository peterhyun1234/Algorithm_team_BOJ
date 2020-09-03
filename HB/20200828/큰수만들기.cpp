#include <string>
#include <vector>

using namespace std;

string solution(string number, int k)
{
    string answer = "";

    int n = number.size() - k;
    int start_idx = 0;
    for (int i = 0; i < n; i++)
    {
        char max_num = number[start_idx];
        int max_idx = start_idx;
        for (int j = start_idx; j <= k + i; j++)
        {
            if (max_num < number[j])
            {
                max_num = number[j];
                max_idx = j;
            }
        }
        start_idx = max_idx + 1;
        answer += max_num;
    }

    return answer;
}