// 수학학원에서 단어 수학 문제를 푸는 숙제
// 수학 문제는 N개의 단어
// 각 단어는 알파벳 대문자로만
// 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제

// GCF + ACDEB를 계산한다고 할 때, 
// A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 두 수의 합은 99437 로 최대!!

// 같은 단어 카운트해서 
// 카운트 순으로 정렬하고
// 높은 카운트 순으로 숫자 할당하고 카운트 곱해서 sum에 저장

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int sum = 0;
	int n;
	vector<int> char_cnts(26); // 대문자만

	cin >> n;
	for (int i = 0; i < n; i++) {
		string input_string;
		cin >> input_string;
		int cnt = 1;
		for (int j = input_string.size()-1; j >= 0; j--) {
			char_cnts[input_string[j] - 'A'] += cnt;
			cnt *= 10;
		}
	}

	sort(char_cnts.begin(), char_cnts.end(), greater<>());

	int ope =9;
	for (int j = 0; j < char_cnts.size(); j++) {
		sum += char_cnts[j] * ope;
		ope--;
	}

	cout << sum << "\n";

	return 0;
}
