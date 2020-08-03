//
//  2644.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/31.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
int main() {
 
    int n, p1, p2, m;
    cin >> n >> p1 >> p2 >> m;
 
    int x, y;
    vector<int> vec[101];
    vector<int> visited(101, 0);
    
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
 
    queue<int> q;
    q.push(p1);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
 
        if (p == p2) {
            break;
        }
 
        for (int i = 0; i < vec[p].size(); i++) {
            if (!visited[vec[p][i]]) {
                visited[vec[p][i]] = visited[p] + 1;
                q.push(vec[p][i]);
            }
        }
    }
 
    if (visited[p2] != 0)
        cout << visited[p2] << endl;
    else
        cout << -1 << endl;
}

/*
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int num, start, goal, first, second, T, map[101][101] = { 0 }, chk[101][101] = { 0 };
    pair<int, int> x;
    queue<pair<int, int> > Q; // 다음 row, cnt
    
    cin >> num;
    cin >> start >> goal;
    cin >> T;
    
    for (int i = 0; i < T; i ++) {
        cin >> first >> second;
        map[first][second] = 1;
        map[second][first] = 1;
    }
    
    Q.push({start, 0});
    
    while(!Q.empty()) {
        x = Q.front();
        Q.pop();
        
        for (int i = 0; i < 10; i ++) {
            if (map[x.first][i] == 1 && chk[x.first][i] == 0) {
                if (i == goal) {
                    cout << x.second + 1 << '\n';
                    exit(0);
                }
                chk[x.first][i] = 1;
                chk[i][x.first] = 1;
                Q.push({i, x.second + 1});
            }
        }
    }
    
    cout << -1 << '\n';
    
    return 0;
    
    cout << '\n';
    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= num; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
    
}
*/
