#include <iostream>
#include <queue>

using namespace std;

int main() {
	int room;
	int mainD;
	int subD;
	int temp;
	long long int result;
	queue<int> people;

	cin >> room;
	result = room;
	while (room) {
		cin >> temp;
		people.push(temp);
		room--;
	}
	
	cin >> mainD >> subD;

	while (!people.empty()) {
		temp = people.front();
		people.pop();
		temp -= mainD;
		if (temp > 0) {
			result += temp / subD;
			if (temp%subD != 0) {
				result++;
			}
		}
	}

	cout << result;
	cin >> temp;
	return 0;
}