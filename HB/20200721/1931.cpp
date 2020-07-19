#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct meeting {
	int starting_time;
	int ending_time;
};

bool compare(meeting a, meeting b) {
	if (a.ending_time == b.ending_time) {
		return a.starting_time < b.starting_time;
	}
	else {
		return a.ending_time < b.ending_time;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	vector<meeting> meetings(n);

	int max_reservations = 1;

	for (int i = 0; i < n; i++) {
		cin >> meetings[i].starting_time;
		cin >> meetings[i].ending_time;
	}

	sort(meetings.begin(), meetings.end(), compare);

	meeting current_meeting = meetings[0];

	for (int i = 1; i < n; i++) {
		if (current_meeting.ending_time <= meetings[i].starting_time) {
			max_reservations ++;
			current_meeting = meetings[i];
		}
	}

	cout << max_reservations << "\n";


	return 0;
}