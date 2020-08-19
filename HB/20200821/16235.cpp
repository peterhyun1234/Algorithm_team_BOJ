// 최근 N×N 크기의 땅을 구매
// 각의 칸은 (r, c)로 나타내며,
// r은 가장 위에서부터 떨어진 칸의 개수,
// c는 가장 왼쪽으로부터 떨어진 칸의 개수

// 땅의 양분을 조사하는 로봇 S2D2
// 가장 처음에 양분은 모든 칸에 5

// 나무 재테크란 작은 묘목을 구매해 어느정도 키운 후 팔아서 수익을 얻는
// M개의 나무를 구매해 땅에 심었다

// 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가
// 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다
// 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.

// 여름에는 봄에 죽은 나무가 양분으로 변하게 된다.
// 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가 (소수점 아래는 버린다)

// 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
// 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다.
// 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.

// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다.
// 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.

// K년이 지난 후 상도의 땅에 살아있는 나무의 개수

// 시뮬 문제

#include <iostream>
#include <vector>
#include <algorithm>

#define max_int 11
#define max_val 1001

using namespace std;

int n, m, k;
int ground[max_int][max_int];
int a[max_int][max_int];
int dead[max_int][max_int];

int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, 1, -1};

vector<int> tree[max_int][max_int];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            ground[i][j] = 5;
        }
    }
    int x, y, z;
    int alive_trees;

    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
        alive_trees++;
    }

    for (int year = 1; year <= k; year++)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                sort(tree[i][j].begin(), tree[i][j].end());
                ground[i][j] += dead[i][j];
                dead[i][j] = 0;
            }
        }

        // 봄, 여름
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 0; k < tree[i][j].size(); k++)
                {
                    if (ground[i][j] >= tree[i][j][k])
                    {
                        ground[i][j] -= tree[i][j][k];
                        tree[i][j][k] += 1;
                    }
                    else
                    {
                        int idx = k;
                        int size = tree[i][j].size();

                        for (int l = size - 1; l >= idx; l--)
                        {
                            dead[i][j] += (tree[i][j][l] / 2);
                            tree[i][j].pop_back();
                            alive_trees--;
                        }
                        break;
                    }
                }
            }
        }

        // 가을
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int s = 0; s < tree[i][j].size(); s++)
                {
                    int tree = tree[i][j][s];
                    if (tree % 5 != 0)
                        continue;

                    for (int k = 0; k < 8; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx > n || nx < 1 || ny > n || ny < 1)
                            continue;

                        tree[nx][ny].push_back(1);
                        alive_trees++;
                    }
                }
            }
        }

        // 겨울
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // S2D2 기계가 양분을 더해줍니다.
                ground[i][j] += a[i][j];
            }
        }
    }

    cout << alive_trees << "\n";
}