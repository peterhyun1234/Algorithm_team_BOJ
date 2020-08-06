// 손님을 도착지로 데려다줄 때마다 연료가 충전
// 연료가 바닥나면 그 날의 업무가 끝난다.
// M명의 승객을 태우는 것이 목표
// 활동할 영역은 N×N 크기의 격자
// 알고리즘 경력이 많은 백준은 특정 위치로 이동할 때 항상 최단경로로만 이동
// M명의 승객은 빈칸 중 하나에 서있음


// 백준이 태울 승객을 고를 때는 현재 위치에서 최단거리가 가장 짧은 승객을 고른다
// 그런 승객이 여러 명이면 그중 행 번호가 가장 작은 승객
// 그런 승객도 여러 명이면 그중 열 번호가 가장 작은 승객

// 연료는 한 칸 이동할 때마다 1만큼 소모된다
// 목적지로 성공적으로 이동시키면 소모한 연료 양의 두 배가 충전된다

// 2 ≤ N ≤ 20, 1 ≤ M ≤ N2, 1 ≤ 초기 연료 ≤ 500, 000
// 연료는 무한히 많이 담을 수 있음

// 최단 경로(어떤 승객 선택할지 + dest까지 가는 최단 경로)는 BFS
// 1. 택시에서 각 승객까지 거리 계산 ㄱㄱ
// 2. 승객까지 이동 후 dest[승객]까지 ㄱㄱ
// 3. 다른 승객 거리 계산 ㄱㄱ + 반복

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct position {
	int x;
	int y;
};

struct passenger {
	int curr_x;
	int curr_y;
	int dest_x;
	int dest_y;
	bool done = false;
};

int n, m;
int fuel;
position taxi_position;

int map[22][22];
int path[22][22];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void print() {
	cout << "\n";

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << path[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void path_init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			path[i][j] = map[i][j];
		}
	}
}


int bfs(int dest_x, int dest_y ) {
	queue<position> queue;
	queue.push({ taxi_position.x, taxi_position.y });
	path[taxi_position.y][taxi_position.x] = 1;
	while (!queue.empty()) {
		int x = queue.front().x;
		int y = queue.front().y;
		queue.pop();

		if (x == dest_x && y == dest_y) {
			return path[y][x] - 1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || nx >= n + 1 || ny < 1 || ny >= n + 1) continue;
			if (path[ny][nx]) continue;

			path[ny][nx] = path[y][x] + 1;
			queue.push({ nx, ny });
		}
		//print();
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> fuel;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	cin >> taxi_position.y >> taxi_position.x;

	vector<passenger> passengers;

	for (int i = 0; i < m; i++) {
		passenger input_passenger;
		cin >> input_passenger.curr_y >> input_passenger.curr_x >> input_passenger.dest_y >> input_passenger.dest_x;
		passengers.push_back(input_passenger);
	}


	while (true) {
		int end_flag = true;

		for (int i = 0; i < m; i++) {
			if (passengers[i].done == false) end_flag = false; // 남은 승객있으면 keep_going
		}

		if (end_flag) { // 정답 출력하고 종료
			cout << fuel << "\n";
			break;
		}


		int min_distance = INT_MAX;
		int cur_distance = 0;
		int min_idx = 0;
		position min_idx_position = {n, n};

		// 1. 다음 목적지 찾기
		for (int i = 0; i < m; i++) {
		
			if (passengers[i].done) continue;

			path_init();
			cur_distance = bfs(passengers[i].curr_x, passengers[i].curr_y);

			if (cur_distance < min_distance) {
				min_distance = cur_distance;
				min_idx = i;
				min_idx_position = { passengers[i].curr_x, passengers[i].curr_y };
			}
			else if (cur_distance == min_distance) {
				if (passengers[i].curr_y < min_idx_position.y) {
					min_idx = i;
					min_idx_position = { passengers[i].curr_x, passengers[i].curr_y };
				}
				else if (passengers[i].curr_y == min_idx_position.y) {
					if (passengers[i].curr_x < min_idx_position.x) {
						min_idx = i;
						min_idx_position = { passengers[i].curr_x, passengers[i].curr_y };
					}
				}
			}
		}


		// 2.1. 연료 충분하면 사람 태우고
		if (fuel >= min_distance) {
			fuel -= min_distance;
			taxi_position = min_idx_position;

			//cout << fuel << "\n";
		}
		else {
			cout << "-1" << "\n";
			break;
		}

		// 2.2. 목적지까지 이동
		path_init();
		int operation_distance;
		operation_distance = bfs(passengers[min_idx].dest_x, passengers[min_idx].dest_y);

		if (fuel >= operation_distance) {
			fuel += operation_distance; // 두배 채움
			taxi_position = { passengers[min_idx].dest_x, passengers[min_idx].dest_y };
			passengers[min_idx].done = true;
			//cout << fuel << "\n";
		}
		else {
			cout << "-1" << "\n";
			break;
		}

	}

	return 0;
}
