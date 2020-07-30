//
//  15686.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/30.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m;
vector<pair<int, int> > hs;
vector<pair<int, int> > pz;
int ch[20], res = 2147000000, dis, sum = 0;

void DFS(int L, int s) {
    if (L == m) {
        sum = 0;
        for (int i = 0; i < hs.size(); i ++) {
            int x1 = hs[i].first;
            int y1 = hs[i].second;
            dis = 2147000000;
            for (int j = 0; j < m; j ++) {
                int x2 = pz[ch[j]].first;
                int y2 = pz[ch[j]].second;
                dis = min(dis, abs(x1 - x2) + abs(y1 - y2));
            }
            sum = sum + dis;
        }
        if (sum < res) res = sum;
    } else {
        for (int i = s; i < pz.size(); i ++) {
            ch[L] = i;
            DFS(L + 1, i + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, a;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> a;
            if (a == 1) hs.push_back(make_pair(i, j));
            else if (a == 2) pz.push_back(make_pair(i, j));
        }
    }
    
    DFS(0, 0);
    
    cout << res << '\n';
    
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int map[55][55], N, M, result = 0;
vector<pair<int, int> > home;
vector<pair<int, int> > chicken_house;
vector<pair<int, int> > dis(13, {0, 0});

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) home.push_back({i, j});
            if (map[i][j] == 2) chicken_house.push_back({i, j});
        }
    }
    
    dis.resize(chicken_house.size(), {0, 0});
    
    for (int i = 0; i < home.size(); i ++) {
        for (int j = 0; j < chicken_house.size(); j ++) {
            dis[j].first += abs(chicken_house[j].first - home[i].first) + abs(chicken_house[j].second - home[i].second);
            dis[j].second = j;
        }
    }
    
    sort(dis.begin(), dis.end());
    
    for (int i = M; i < chicken_house.size(); i ++) {
        map[chicken_house[dis[i].second].first][chicken_house[dis[i].second].second] = 0;
    }
    
    for (int i = 0; i < home.size(); i ++) {
        int min_dis = 2147000000;
        for (int j = 0; j < M; j++) {
            int tmp = abs(chicken_house[dis[j].second].first - home[i].first) + abs(chicken_house[dis[j].second].second - home[i].second);
            if (tmp < min_dis) min_dis = tmp;
        }
        result += min_dis;
    }
    
    cout << result << '\n';
    
    
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j ++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    
    
    return 0;
}
*/
