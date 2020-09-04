#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;

int Find(int v) {
    if (parent[v] == v) return v;
    else return Find(parent[v]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[a] = b;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> chk(n, 0);
    vector<vector<int>> map(n, vector<int>(n, 0));
    parent.resize(n);
    
    for (int i = 0; i < n; i ++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (i != j && computers[i][j] == 1 && map[i][j] == 0) {
                Union(i, j);
                map[i][j] = 1;
                map[j][i] = 1;
            }
        }
    }
    
    for (int i = 0; i < chk.size(); i ++) {
        chk[i] = Find(i);
    }
    
    sort(chk.begin(), chk.end());
    
    for (int i = 0; i < chk.size() - 1; i ++) {
        if (chk[i] != chk[i + 1])
            answer ++;
    }
    
    return answer + 1;
}
