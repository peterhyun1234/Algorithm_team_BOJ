#include <string>
#include <vector>

using namespace std;

void dfs(int cur_idx, int n, vector<int> &path, vector<vector<int>> &computers) {

    for (int i = 0; i < n; i++) {
        if (cur_idx != i && computers[cur_idx][i] == 1 && path[i] == 0) {
            path[i] = 1;
            dfs(i, n, path, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    int answer = 0;
    vector<int> path(n, 0);

    for (int i = 0; i <n; i++) {
        if (path[i] == 1) {
            continue;
        }

        answer++;
        path[i] = 1;

        dfs(i, n, path, computers);
    }

    return answer;
}