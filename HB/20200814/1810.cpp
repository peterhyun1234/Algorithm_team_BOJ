// 징검다리 위를 달리는 경기
// 징검다리가 놓여 있는 위치는 (x, y) 
// 시작점은 언제나 (0,0) 원점
// 현재 위치한 징검다리와 x좌표 차이가 2 이하이고, y좌표 차이도 2 이하인 징검다리로만 점프
// 결승선은 x축에 평행한 직선 (y좌표가 동일한 징검다리에 도달하면 결승선을 통과)

// (x1, y1)에 위치한 징검다리에서 (x2, y2)에 위치한 징검다리로의 점프는 루트((x1-x2)^2+(y1-y2)^2)의 길이
// 둘째 줄부터는 N개의 징검다리들의 좌표
// 경로를 구성하고 있는 점프들의 길이 합이 최소인 경로

// 오히려 다익스트라보다 BFS로 푸는 게 좋을 거 같은데;;


// BFS 시간 초과!!!!
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//#include <cmath>
//#include <climits>
//
//struct stone
//{
//	double dist;
//	int x, y, i;
//	bool operator > (const stone& n) const {
//		return dist > n.dist;
//	}
//};
//
//int dx[] = {-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,1,1,1,1,1,2,2,2,2,2};
//int dy[] = {-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
//
//using namespace std;
//
//vector<stone> stepping_stone;
//
//int path[50001] = { 0, };
//
//int n, f;
//
//int jump_possible(int x, int y) {
//	for (int i = 0; i <= n; i++) {
//		if (x == stepping_stone[i].x && y == stepping_stone[i].y) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> n >> f;
//
//	stepping_stone.push_back({ 0 , 0 }); // 시작 점!
//
//	for (int i = 1; i <= n; i++) {
//		int input_x, input_y;
//		cin >> input_x >> input_y;
//		stepping_stone.push_back({input_x , input_y });
//	}
//
//	queue<stone> q;
//
//	q.push({ 0,0 });
//
//	int shortest_distance = INT_MAX;
//
//	path[0] = 1;
//
//	while (!q.empty())
//	{
//		stone curr_stone = q.front();
//		q.pop();
//
//		int curr_idx = jump_possible(curr_stone.x, curr_stone.y);
//
//		if (curr_stone.y >= f) {
//			shortest_distance = min(shortest_distance, path[curr_idx]);
//		}
//
//		for (int i = 0; i < 24; i++) {
//			int nx = curr_stone.x + dx[i];
//			int ny = curr_stone.y + dy[i];
//
//			if (nx < 0 || ny < 0) continue;
//
//			int jump_idx = jump_possible(nx, ny);
//			if (jump_idx == -1) {
//				continue;
//			}
//			else { // 점프 가능
//				if (path[jump_idx]) {
//					continue;
//				}
//				else {
//					int between_distanse = sqrt(pow(nx - curr_stone.x, 2) + pow(ny - curr_stone.y, 2));
//					path[jump_idx] = between_distanse + path[curr_idx];
//					q.push({ nx,ny });
//				}
//			}
//		}
//	}
//
//	cout << shortest_distance << "\n";
//
//	return 0;
//}



// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// #include <cmath>
// #include <climits>

// using namespace std;

// struct stone
// {
// 	double dist;
// 	int x, y, i;
// 	bool operator > (const stone& n) const {
// 		return dist > n.dist;
// 	}
// };

// vector<pair<int, int>> gragh[10000001];

// int dist[50001] = { 0, };

// priority_queue<stone, vector<stone>, greater<stone>> pq;

// int n, f;

// int main()
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	cin >> n >> f;

// 	//stepping_stone.push_back({ 0 , 0 }); // 시작 점!

// 	for (int i = 1; i <= n; i++) {
// 		int input_x, input_y;
// 		cin >> input_x >> input_y;
// 		gragh[input_y].push_back({ input_x , i });
// 	}

// 	for (int i = 0; i < 10000001; i++) {
// 		dist[i] = INT_MAX;
// 	}

// 	queue<stone> q;

// 	q.push({ 0,0 });

// 	int shortest_distance = INT_MAX;

// 	path[0] = 1;

// 	while (!q.empty())
// 	{
// 		stone curr_stone = q.front();
// 		q.pop();

// 		int curr_idx = jump_possible(curr_stone.x, curr_stone.y);

// 		if (curr_stone.y >= f) {
// 			shortest_distance = min(shortest_distance, path[curr_idx]);
// 		}

// 		for (int i = 0; i < 24; i++) {
// 			int nx = curr_stone.x + dx[i];
// 			int ny = curr_stone.y + dy[i];

// 			if (nx < 0 || ny < 0) continue;

// 			int jump_idx = jump_possible(nx, ny);
// 			if (jump_idx == -1) {
// 				continue;
// 			}
// 			else { // 점프 가능
// 				if (path[jump_idx]) {
// 					continue;
// 				}
// 				else {
// 					int between_distanse = sqrt(pow(nx - curr_stone.x, 2) + pow(ny - curr_stone.y, 2));
// 					path[jump_idx] = between_distanse + path[curr_idx];
// 					q.push({ nx,ny });
// 				}
// 			}
// 		}
// 	}

// 	cout << shortest_distance << "\n";

// 	return 0;
// }
