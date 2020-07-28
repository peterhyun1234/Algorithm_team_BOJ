//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//    int n = 10;
//    int input_num;
//    vector<vector<int>> sudoku_numbers(n, vector<int>(n));
//
//    // check rows
//    for (int i = 0; i < n - 1; i++) {
//        int zero_count = 0;
//        int zero_idx = 0;
//        vector<bool> num_check(n, 0);
//        for (int j = 0; j < n - 1; j++) {
//            cin >> input_num;
//            if (input_num == 0) {
//                zero_count++;
//                zero_idx = j;
//            }
//            num_check[input_num] = 1;
//            sudoku_numbers[i][j] = input_num;
//        }
//        if (zero_count == 1) {
//            int one_zero_num;
//            for (int j = 0; j < n; j++) {
//                if (num_check[j] == 0) {
//                    one_zero_num = j;
//                    break;
//                }
//            }
//            sudoku_numbers[i][zero_idx] = one_zero_num;
//        }
//    }
//
//    // check columns
//    for (int i = 0; i < n - 1; i++) {
//        int zero_count = 0;
//        int zero_idx = 0;
//        vector<bool> num_check(n, 0);
//        for (int j = 0; j < n - 1; j++) {
//            input_num = sudoku_numbers[j][i];
//            if (input_num == 0) {
//                zero_count++;
//                zero_idx = j;
//            }
//            num_check[input_num] = 1;
//        }
//        if (zero_count == 1) {
//            int one_zero_num;
//            for (int j = 0; j < n; j++) {
//                if (num_check[j] == 0) {
//                    one_zero_num = j;
//                    break;
//                }
//            }
//            sudoku_numbers[zero_idx][i] = one_zero_num;
//        }
//    }
//
//    // chek squares
//    for (int i = 0; i < n - 1; i++) {
//
//        int x_idx = (i * 3) % 9;
//        int y_idx = (i / 3) * 3;
//        
//
//
//        int zero_count = 0;
//        pair<int, int> zero_idx;
//        vector<bool> num_check(n, 0);
//        for (int y = y_idx; y < y_idx + 3; y++) {
//            for (int x = x_idx; x < x_idx + 3; x++) {
//                input_num = sudoku_numbers[y][x];
//                if (input_num == 0) {
//                    zero_count++;
//                    zero_idx = { y, x };
//                }
//                num_check[input_num] = 1;
//            }
//        }
//        if (zero_count == 1) {
//            int one_zero_num;
//            for (int j = 0; j < n; j++) {
//                if (num_check[j] == 0) {
//                    one_zero_num = j;
//                    break;
//                }
//            }
//            sudoku_numbers[zero_idx.first][zero_idx.second] = one_zero_num;
//        }
//    }
//
//
//    //cout << "\n";
//    //cout << "printed numbers: " <<"\n";
//
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - 1; j++) {
//            cout << sudoku_numbers[i][j] << " ";
//        }
//        cout << "\n";
//    }
//
//    return 0;
//}


// 반례 체크 참고 in https://cryptosalamander.tistory.com/59

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n = 9;
vector<vector<int>> sudoku_numbers(n, vector<int>(n));
vector<pair<int, int>> zero_points;
int zero_cnt = 0;
bool sudoku_complete_flag = false;

bool check(pair<int, int> p)
{
	int point_x = p.first;
	int point_y = p.second;


	for (int i = 0; i < n; i++)
	{
		if (sudoku_numbers[point_x][i] == sudoku_numbers[point_x][point_y] && i != point_y)
			return false; 
		if (sudoku_numbers[i][point_y] == sudoku_numbers[point_x][point_y] && i != point_x)
			return false; 
	}

	int square_x = point_x / 3;
	int square_y = point_y / 3;

	for (int i = 3 * square_x; i < 3 * square_x + 3; i++) {
		for (int j = 3 * square_y; j < 3 * square_y + 3; j++)
		{
			if (sudoku_numbers[i][j] == sudoku_numbers[point_x][point_y])
			{
				if (i != point_x && j != point_y)
					return false; 
			}
		}
	}

	return true;
}

void sudoku(int N) {
	if (N == zero_cnt)
	{
		sudoku_complete_flag = true;
		return;
	}
	for (int j = 1; j <= n; j++)
	{
		sudoku_numbers[zero_points[N].first][zero_points[N].second] = j;
		if (check(zero_points[N]))
			sudoku(N + 1);
		if (sudoku_complete_flag)
			return;
	}
	sudoku_numbers[zero_points[N].first][zero_points[N].second] = 0;
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> sudoku_numbers[i][j];
			if (sudoku_numbers[i][j] == 0)
			{
				zero_cnt++;
				zero_points.push_back({ i, j });
			}
		}
	}

	sudoku(0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << sudoku_numbers[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}