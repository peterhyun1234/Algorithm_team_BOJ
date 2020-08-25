// 해커 김지민은 잘 알려진 어느 회사를 해킹
// N개의 컴퓨터
// 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹
// 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져있음
// A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹
// 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<int> gragh[10000]; 
vector<int> curr_com_nums

bool path[10000];

int dfs(int cur_com_num, int hacked_com_nums){
    for(int i = 0; i < gragh[cur_com_num].length(); i++){
        int next_com_num = gragh[cur_com_num][i];

        if(path[next_com_num]) continue;
        path[next_com_num] = true;
        dfs(next_com_num, hacked_com_nums);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i =0; i < m; i++){
        int to, end;
        cin >> end >> to;
        gragh[to].push_back(end);
    }
    
    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            path[j] =false;
        }
        path[i] = true;
        curr_com_nums.push_back(dfs(i, 0));
    }

    int max_hacked_coms =0;
    for (int i = 0; i < n; i++)
    {
        max_hacked_coms = max(max_hacked_coms, curr_com_nums[i]);
    }
    
    for(int i = 0; i < n; i++){
        if(curr_com_nums[i] == max_hacked_coms){
            cout << i << " ";
        }
    }

    cout << "\n";
 
    return 0;
}