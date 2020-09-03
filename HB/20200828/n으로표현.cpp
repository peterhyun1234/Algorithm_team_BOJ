#include <vector>
#include <algorithm>
using namespace std;
 
int answer = 9;
 
void dfs(int N, int number, int count, int curr_number) {
    if (count >= 9)        return;
    if (curr_number == number) {
        answer = min(answer, count);
        return;
    }
    int next_number = 0;
    for (int i = 0; i + count< 9 ; i++) {
        next_number = next_number * 10 + N;
        dfs(N, number, count + 1 + i, curr_number + next_number);
        dfs(N, number, count + 1 + i, curr_number - next_number);
        dfs(N, number, count + 1 + i, curr_number * next_number);
        dfs(N, number, count + 1 + i, curr_number / next_number);
    }
}
 
int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if (answer == 9)    return -1;
    return answer;
}