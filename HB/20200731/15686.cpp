 // 도시의 각 칸은 빈 칸, 치킨집, 집 중 하나
 // 치킨 거리는 집과 가장 가까운 치킨집 사이의 거리
 // 도시의 치킨 거리는 모든 집의 치킨 거리의 합
 // 도시의 치킨 거리가 가장 작게 될지

 // 0은 빈 칸, 1은 집, 2는 치킨집
 // 모든 집에 대해 제일 가까운 치킨 집까지의 거리의 합 -> DFS!

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
int n, m;
int min_of_citys_distance = INT_MAX;

vector<vector<int>> city(50, vector<int>(50));
vector<pair<int, int>> houses, chicken_houses;
vector<bool> path(13);

void dfs(int idx_ CH, int selected_CH)
{
    if (selected_CH == m)
    {
        int temp_distance = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            int curr_distance = INT_MAX;
            for (int j = 0; j < chicken_houses.size(); j++)
                if (path[j])
                curr_distance = min(curr_distance, abs(houses[i].first - chicken_houses[j].first) + abs(houses[i].second - chicken_houses[j].second));
        
            temp_distance += curr_distance;
        }
        min_of_citys_distance = min(min_of_citys_distance, temp_distance);
        return;
    }

    if (idx_ CH == chicken_houses.size())
        return;


    // 추가하거나 안하거나
    path[idx_ CH] = true;
    dfs(idx_ CH + 1, selected_CH + 1);

    path[idx_ CH] = false;
    dfs(idx_ CH + 1, selected_CH);
}
 
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for(int i=0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            cin >> city[i][j];
            if (city[i][j] == 1)
                houses.push_back({ i, j });
            else if (city[i][j] == 2)
                chicken_houses.push_back({ i, j });
        }
    }

    dfs(0, 0);
    cout << min_of_citys_distance << "\n";
    return 0;
}
