// push X: 정수 X를 큐에 넣는 연산이다.
// pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// size: 큐에 들어있는 정수의 개수를 출력한다.
// empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
// front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
// back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
    cin.tie(0);
    cin.sync_with_stdio(0);
	int num, data;
	queue<int> q; 
    string str;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> str;

		if (str == "push") {
			cin >> data;
			q.push(data);
		}
		else if (str == "pop") {
			if (q.size() == 0) std::cout << "-1\n";
			else {
				data = q.front();
				q.pop();
				cout << data << "\n";
			}
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			cout << q.empty() << "\n";
		}
		else if (str == "front") {
			if (q.size() == 0) std::cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (str == "back") {
			if (q.size() == 0) std::cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
	return 0;
}