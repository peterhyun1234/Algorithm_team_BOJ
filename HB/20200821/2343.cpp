// 기타 레슨 동영상을 블루레이로 만들어 판매
// 블루레이에는 총 N개의 레슨
// 블루레이를 녹화할 때, 레슨의 순서가 바뀌면 안 된다
// i번 레슨과 j번 레슨을 같은 블루레이에 녹화하려면 i와 j 사이의 모든 레슨도 같은 블루레이에 녹화
// 블루레이의 개수를 가급적 줄이려고

// M개의 블루레이에 모든 기타 레슨 동영상을 녹화하기
// M개의 블루레이는 모두 같은 크기
// 가능한 블루레이의 크기 중 최소

// 첫째 줄에 레슨의 수 N (1 ≤ N ≤ 100,000), M (1 ≤ M ≤ N)
// 강토의 기타 레슨의 길이가 레슨 순서대로 분 단위로(자연수)

// 이건 이분탐색이지 ㅅㅂ

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 100000;

int N, M;
int blueray[MAX];

bool func(int mid)
{
    int sum = 0;
    int num = 1;

    for (int i = 0; i < N; i++)
    {
        if (blueray[i] > mid)
            return false;

        sum += blueray[i];

        if (sum > mid)
        {
            sum = blueray[i];
            num++;
        }
    }

    return M >= num;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> blueray[i];
        sum += blueray[i];
    }

    int low = 1, high = sum;
    int result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (func(mid))
        {
            result = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    cout << result << "\n";

    return 0;
}
