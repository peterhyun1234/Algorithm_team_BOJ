// N(2≤N≤10000)개의 섬으로 이루어진 나라
// 몇 개의 섬 사이에는 다리가 설치되어 있음
// 각각의 다리마다 중량제한이 있기 때문에 무턱대고 물품을 옮길 순 없다 (이분 탐색)
// 한 번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값
// 마지막 줄에는 공장이 위치해 있는 섬의 번호

// 공통 중량? 을 이분 탐색으로, BFS 돌려서 가능하면 정답 ㄱㄱ

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct bridge {
	int end;
	int weight;
};

vector<bridge> bridges[100000];
int island_1, island_2;
bool path[100000];
int max_weight = 0;

bool bfs(int cost)
{
    queue<int> q;
    q.push(island_1);
    path[island_1] = true;

    while (!q.empty())
    {
        int curr_factory = q.front();
        q.pop();

        if (curr_factory == island_2)
            return true;

        for (int i = 0; i < bridges[curr_factory].size(); i++)
        {
            int nfactory = bridges[curr_factory][i].end;
            int nweight = bridges[curr_factory][i].weight;

            if (!path[nfactory] && cost <= nweight)
            {
                path[nfactory] = true;
                q.push(nfactory);
            }
        }
    }
    return false;
}

void init_path() {
    for (int i = 0; i < sizeof(path); i++) {
        path[i] = false;
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
    
	for (int i = 0; i < m; i++) {
		int a, b, c;
        cin >> a >> b >> c;
		bridges[a].push_back({ b,c });
		bridges[b].push_back({ a,c });
        max_weight = max(max_weight, c);
	}

	cin >> island_1 >> island_2;

    int left = 0;
    int right = max_weight;
    int mid = left + (right - left) / 2;

    while (left <= right) {
        mid = left + (right - left) / 2;

        init_path();
        if (bfs(mid)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << right << "\n";

	return 0;
}
