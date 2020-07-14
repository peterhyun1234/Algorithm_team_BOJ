#include <iostream>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(0);
	cout.tie(0);

	string input_line;

	getline(cin, input_line);

	int inputlen = input_line.size();
	int word_count;

	if (input_line[0] == ' ')
		word_count = 0;
	else
		word_count = 1;

	for (int i = 1; i < inputlen; i++) {
		if (input_line[i-1] == ' '&& input_line[i] >= 65) {
			word_count++;
		}
	}

	cout << word_count << "\n";


	return 0;
}