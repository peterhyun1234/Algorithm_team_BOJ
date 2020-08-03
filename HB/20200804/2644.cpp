// 여러 사람들에 대한 부모 자식들 간의 관계가 주어졌을 때, 주어진 두 사람의 촌수를 계산
// 첫째 줄에는 전체 사람의 수 n
// 둘째 줄에는 촌수를 계산해야 하는 서로 다른 두 사람의 번호
// 셋째 줄에는 부모 자식들 간의 관계의 개수 m
// 넷째 줄부터는 부모 자식간의 관계를 나타내는 두 번호 x,y가 각 줄에 나온다. 
// 이때 앞에 나오는 번호 x는 뒤에 나오는 정수 y의 부모 번호를 나타낸다.
// 어떤 경우에는 두 사람의 친척 관계가 전혀 없어 촌수를 계산할 수 없을 때가 있다. 이때에는 -1

// 친척 부모 관계를 어떻게 해야할지 생각이 안나서 참고.. 익숙할 때 까지 풀자!
// https://suriisurii.tistory.com/40

#include<iostream>
#include<queue>
using namespace std;

int n, relative_1, relative_2, m;
int relation[101][101];
int path[101];

int main() {
    cin >> n >> relative_1 >> relative_2 >> m;
    for (int i = 0; i < m; i++) {
        int x = 0, y = 0;
        cin >> x >> y;
        relation[x][y] = relation[y][x] = 1;
    }
 
    queue<int> q;
    q.push(relative_1);
    while (!q.empty()) {
        int now = q.front(); 
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (relation[now][i] == 0 || path[i] != 0) continue;
            path[i] = path[now] + 1;
            q.push(i);
        }
    }

    cout << (path[relative_2] == 0 ? -1 : path[relative_2]) << "\n";
    return 0;
}