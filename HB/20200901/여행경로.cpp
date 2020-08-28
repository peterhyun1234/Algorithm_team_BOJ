#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;

bool dfs(string curr_airport, vector<vector<string>> &tickets, vector<bool> &visited, vector<string> &path, int cnt)
{
    path.push_back(curr_airport);
    if (cnt == tickets.size())
    {
        answer = path;
        return true;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if (tickets[i][0] == curr_airport && visited[i] == false)
        {
            visited[i] = true;
            bool success = dfs(tickets[i][1], tickets, visited, path, cnt + 1);
            if (success)
                return true;
            visited[i] = false;
        }
    }
    path.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> path;
    int n = tickets.size();
    vector<bool> visited(n);
    string start_airport = "ICN";

    sort(tickets.begin(), tickets.end());
    dfs(start_airport, tickets, visited, path,  0);

    return answer;
}
