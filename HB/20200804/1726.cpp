#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
    int x, y;
    int dir;
    int operations = 0;
};

int m, n;
int factory[101][101];
bool path[101][101][5];

int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 };

node start_position, dest_position;

bool pruning(int x, int y, int d, int k)
{
    int nx = x + dx[d] * k;
    int ny = y + dy[d] * k;

    if (nx < 1 || ny < 1 || nx > m || ny > n) return false;

    nx = x;
    ny = y;

    for (int i = 0; i < k; i++)
    {
        nx = nx + dx[d];
        ny = ny + dy[d];

        if (factory[nx][ny] == 1) return false;
    }
    return true;
}

int direction_change(int d, char c)
{
    if (c == 'L')
    {
        if (d == 1) return 4;
        else if (d == 2) return 3;
        else if (d == 3) return 1;
        else if (d == 4) return 2;
    }
    else if (c == 'R')
    {
        if (d == 1) return 3;
        else if (d == 2) return 4;
        else if (d == 3) return 2;
        else if (d == 4) return 1;
    }
}

void bfs()
{
    queue<node> queue;
    queue.push(start_position);

    while (!queue.empty())
    {
        int x = queue.front().x;
        int y = queue.front().y;
        int d = queue.front().dir;
        int operations = queue.front().operations;
        queue.pop();

        if (x == dest_position.x && y == dest_position.y && d == dest_position.dir)
        {
            cout << operations << "\n";
            return;
        }

        for (int i = 1; i <= 3; i++)
        {
            if (pruning(x, y, d, i) == true)
            {
                int nx = x + dx[d] * i;
                int ny = y + dy[d] * i;

                if (path[nx][ny][d] == false)
                {
                    path[nx][ny][d] = true;
                    queue.push({ nx, ny, d, operations + 1 });
                }
            }
        }

        int nd;
        nd = direction_change(d, 'L');
        if (path[x][y][nd] == false)
        {
            path[x][y][nd] = true;
            queue.push({ x, y, nd, operations + 1 });
        }

        nd = direction_change(d, 'R');
        if (path[x][y][nd] == false)
        {
            path[x][y][nd] = true;
            queue.push({ x, y, nd, operations + 1 });
        }
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> factory[i][j];
        }
    }
    cin >> start_position.x >> start_position.y >> start_position.dir;
    cin >> dest_position.x >> dest_position.y >> dest_position.dir;

    bfs();
    return 0;
}
