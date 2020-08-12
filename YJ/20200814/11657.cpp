//
//  11657.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/11.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#define INF 99999999

using namespace std;

int N, M;
vector<pair<int, int>> v[502];
long long dist[501] = { INF, };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c;
    bool cycle = false;
    
    cin >> N >> M;
    
    while (M--) {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }

    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    
    dist[1] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < v[j].size(); k++) {
                int cur = v[j][k].first;
                int cost = v[j][k].second;
                if (dist[j] != INF && j != cur && dist[cur] > cost + dist[j]) {
                    dist[cur] = cost + dist[j]; //최소값으로 갱신
                    if (i == N) cycle = true;
                }
            }
        }
    }

    if (cycle) cout << -1 << endl;
    
    else
    {
        for (int i = 2; i <= N; i++)
        {
            if (dist[i] == INF) cout << -1 << endl;
            else cout << dist[i] << endl;
        }

    }
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct bus {
    int start, end, dist;
    bus(int a, int b, int c) {
        start = a;
        end = b;
        dist = c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, a, b, c;
    vector<bus> buses;
    
    cin >> N >> M;
    
    vector<int> dist(N + 1, INT_MAX);

    for (int i = 0; i < M; i ++) {
        cin >> a >> b >> c;
        buses.push_back(bus(a, b, c));
    }
    
    dist[1] = 0;
    
    for (int i = 1; i < M; i ++) {
        for (int j = 0; j < buses.size(); j ++) {
            int now_start = buses[j].start;
            int now_end = buses[j].end;
            int now_dist = buses[j].dist;
            
            if (dist[now_start] != INT_MAX && now_dist + dist[now_start] < dist[now_end]) {
                dist[now_end] = dist[now_start] + now_dist;
            }
        }
    }
    
    for (int i = 0; i < buses.size(); i ++) {
        int a = buses[i].start;
        int b = buses[i].end;
        int c = buses[i].dist;
        if (dist[a] != INT_MAX && dist[a] + c < dist[b]) {
            cout << -1 << '\n';
            exit(0);
        }
    }
    
    for (int i = 2; i <= N; i ++) {
        if (dist[i] != INT_MAX) cout << dist[i] << '\n';
        else cout << -1 << '\n';
    }
    
    return 0;
}
*/
