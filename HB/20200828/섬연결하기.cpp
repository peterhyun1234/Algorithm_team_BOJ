#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

struct edge
{
    int end;
    int cost;
};
vector<edge> node[100];
//set<int> node_num;
int min_cost = INT_MAX;

void init_path(int n, bool path[])
{
    for (int i = 0; i < n; i++)
    {
        path[i] = false;
    }
}

void dfs(int cur_idx, int depth, int n, int total_cost, bool path[])
{
    if (depth == n)
    {
        min_cost = min(min_cost, total_cost);
    }

    for (int i = 0; i < node[cur_idx].size(); i++)
    {
        int next_idx = node[cur_idx][i].end;
        int next_cost = node[cur_idx][i].cost;

        if (path[next_idx])
            continue;

        path[next_idx] = true;
        dfs(next_idx, depth + 1, n, total_cost + next_cost, path);
    }
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;

    //dfs + djikstra로 풀어보자

    int to, end, cost;
    for (int i = 0; i < costs.size(); i++)
    {
        to = costs[i][0];
        end = costs[i][1];
        cost = costs[i][2];
        node[to].push_back({end, cost});
        node[end].push_back({to, cost});
        //node_num.insert(to);
        //node_num.insert(end);
    }

    bool path[100];
    for (int i = 0; i < n; i++)
    {
        init_path(n, path);
        path[i] = true;
        dfs(i, 1, n, 0, path);
    }

    /*for(auto iter = node_num.begin(); iter != node_num.end(); iter++){
        cout << *iter << "\n";
    }*/

    answer = min_cost;

    return answer;
}

// 크루스칼 코드
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int getParent(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent, parent[x]);
}

void unionParent(vector<int> &parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    a < b ? parent[b] = a : parent[a] = b;
}

bool find(vector<int> &parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    return a == b;
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0, max = 0;
    sort(costs.begin(), costs.end(), cmp);
    for (auto a : costs)
        if (max < a[1])
            max = a[1];
    vector<int> parent;
    for (int i = 0; i <= max; i++)
        parent.push_back(i);
    for (auto a : costs)
    {
        if (!find(parent, a[0], a[1]))
        {
            answer += a[2];
            unionParent(parent, a[0], a[1]);
        }
    }
    return answer;
}