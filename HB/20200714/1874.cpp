#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
	int n;
	vector<int> input_vec;
	stack<int> s;
	vector<char> ouput_vec;
	cin >> n;


	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		input_vec.push_back(k);

	}

	/*for (int i = 0; i < n; i++) {
		cout << input_vec[i] << "\n";
	}*/

	vector<int>::iterator iterator;

	iterator = input_vec.begin();

	for (int i = 1; i <= n; i++) {
		s.push(i);
		ouput_vec.push_back('+');

		while (!s.empty()) {
			if (*iterator != s.top()) {
				break;
			}
			else {
				s.pop();
				ouput_vec.push_back('-');
				iterator++;
			}
		}

		/*for (int i = 0; i < s.size(); i++) {
			cout << s[i] << "\n";
		}*/
	}

	if (s.empty()) {
		for (int i = 0; i < ouput_vec.size(); i++)
			cout << ouput_vec[i] << "\n";
	}
	else {
		cout << "NO";
	}

	return 0;
}