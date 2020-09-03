#include <string>
#include <vector>

using namespace std;

int degree_of_total_method = 0;

void dfs(vector<int> &numbers, int &target, int sum, int n)
{
    if (n == numbers.size())
    {
        if (sum == target)
            degree_of_total_method++;
        return;
    }

    dfs(numbers, target, sum + numbers[n], n + 1);
    dfs(numbers, target, sum - numbers[n], n + 1);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;

    dfs(numbers, target, numbers[0], 1);
    dfs(numbers, target, -numbers[0], 1);

    answer = degree_of_total_method;

    return answer;
}