// 독일 로또는 {1, 2, ..., 49}에서 수 6개
// k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택
// BFS나 DFS로 풀면되는데 예제보니 DFS로 풀어보는 게 좋을듯

//그리고 전역변수 쓰는게 오히려 직관적임;;

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void dfs(vector<int> S, vector<int> Selected_nums, int depth, int idx, int Selecting_num)
{
	if (depth == Selecting_num)
	{
		for (int i = 0; i < Selecting_num; i++)
			cout << Selected_nums[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < S.size(); i++)
	{
		Selected_nums[depth] = S[i];
		dfs(S, Selected_nums, depth + 1, i + 1, Selecting_num);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int selecting_num = 6;

	while (true)
	{
		int k;
		cin >> k;
		if (!k)
			break;

		vector<int> s(k);
		vector<int> selected_nums(selecting_num);

		for (int i = 0; i < k; i++)
			cin >> s[i];

		dfs(s, selected_nums, 0, 0, selecting_num);

		cout << "\n";
	}
	return 0;
}