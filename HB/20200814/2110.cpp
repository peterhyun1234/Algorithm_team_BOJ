// 도현이의 집 N개가 수직선 위에 있다.
// 도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치
// 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 
// 한 집에는 공유기를 하나만 설치할 수 있고, 
// 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여

// C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대

// 첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)
// 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi
// 두 공유기 사이의 최대 거리를 출력
// tlqkf tlqkf tlqkf 키보드 고장났다()

// 정렬해서 upper_bound로 풀면 될 듯 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int c, n;
	cin >> n >> c;

	vector<int> house_positions(n);

	for (int i = 0; i < n; i++) {
		cin >> house_positions[i];
	}

	sort(house_positions.begin(), house_positions.end());

    int distance_left = 1;
    int distance_right = house_positions[n-1];
    int max_inteval = 0;

    while (distance_left <= distance_right) {
        int mid = (distance_left + distance_right) / 2;
        int degree_of_routers = 1;
        int curr_position = house_positions[0];

        for (int i = 1; i < n; i++)
        {
            int curr_distance = house_positions[i] - curr_position;
            if (curr_distance >= mid) {
                curr_position = house_positions[i];
                degree_of_routers++;
            }
        }
 
        //if (degree_of_routers == c) 같은 경우만 찾았는데 반례가 있었다;

        if (degree_of_routers >= c)
        {
            max_inteval = mid;
            distance_left = mid + 1;
        }
        else distance_right = mid - 1;
    }

    cout << max_inteval << "\n";

	return 0;
}