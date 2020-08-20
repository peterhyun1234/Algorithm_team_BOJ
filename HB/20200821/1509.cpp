// ABACABA를 팰린드롬으로 분할하면, 
// {A, B, A, C, A, B, A}, 
// {A, BACAB, A}, 
// {ABA, C, ABA}, 
// {ABACABA}등이 있다.

// 분할의 개수의 최솟값을 출력

// 뭔말이지 이게???
// 팰린드롬의 길이가 긴것들을 모아서 갯수를 판별하면 될듯

// BB
// C
// DD
// E
// C
// A
// E
// C
// B
// DABAD
// D
// C
// E
// B
// A
// CCC
// B
// D
// C
// A
// ABDBA
// DD

// 이건 ㄹㅇ 어떻게 풀어야할지 모르겠다
// 개똑똑이가 풀었나보다 ㅅㅂ

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int pld[2501][2501];
    int d[2501];

	cin >> s;

	s.insert(0, " ");
	int N = s.length();

	for (int i = 1; i <= N; i++) pld[i][i] = 1; //1
	for (int i = 1; i < N; i++) if (s[i] == s[i + 1]) pld[i][i + 1] = 1; //2
	//3이상
	for (int i = 2; i < N; i++)
		for (int j = 1; j <= N - i; j++)
			if (s[j] == s[j + i] && pld[j + 1][j + i - 1]) pld[j][j + i] = 1;

	for (int i = 1; i < N; i++){
		d[i] = INT_MAX;
		for (int j = 1; j <= i; j++){
			if (pld[j][i]) d[i] = min(d[i], d[j - 1] + 1);
		}
	}
	cout << d[N-1] << "\n";
	return 0;
}