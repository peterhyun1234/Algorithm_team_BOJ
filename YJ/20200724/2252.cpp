//
//  2252_1.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/23.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int indegree[32001] = {0, }; // 해당 칸 기준 앞에 설 사람의 수
vector<int> back_people_nums[32001]; // 해당 칸 기준 그 사람 뒤에 설 사람의 숫자(이름) -> 이차원 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, a, b;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        indegree[b]++;
        back_people_nums[a].push_back(b);
    }

    queue<int> ans;
    
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0) ans.push(i);

    while(!ans.empty()) {
        int i = ans.front();
        ans.pop();
        cout << i << ' ';

        for(int j = 0; j < back_people_nums[i].size(); j++)
            if (--indegree[back_people_nums[i][j]] == 0)
                ans.push(back_people_nums[i][j]);
    }
}

/* test case
5 3
1 4
2 4
4 3
*/
