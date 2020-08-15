// n개의 포트가 다른 n개의 포트와 어떻게 연결되어야 하는지가 주어졌을 때,
// 연결선이 서로 꼬이지(겹치지, 교차하지) 않도록 하면서 최대 몇 개까지 연결할 수 있는지
// 첫째 줄에 최대 연결 개수를 출력

// dfs는 시간 초과!

// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>

// using namespace std;
// int n;
// vector<int> connecting_lines;
// bool path[40000];
// int curr_lines = 0;

// struct port{
//     int curr_x = 0;
//     int dest_x = 0;
//     int curr_y, dest_y;
// };

// void init_path(){
//     for(int i = 0 ; i < n; i++)
//         path[i] = false;
// }


// bool have_contact(int start_linenum){
//     이미 연결된 라인들 중에서 접점이 있는지 찾기
//     port target_line;
//     target_line.curr_y = start_linenum;
//     target_line.dest_y = connecting_lines[start_linenum];
    
//     port curr_line;
//     for(int i = 0; i < n; i++){
//         if(path[i]){
//             curr_line.curr_y = i;
//             curr_line.dest_y = connecting_lines[i];
//             if(target_line.curr_y > curr_line.curr_y && target_line.dest_y <= curr_line.dest_y ){
//                 return true;
//             }
//             if(target_line.curr_y < curr_line.curr_y && target_line.dest_y >= curr_line.dest_y ){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// void dfs(int connected_lines){
//     curr_lines = max(curr_lines, connected_lines);

//     for(int i = 0; i < n; i++){
//         if(path[i]) continue; // 이미 연결한 라인
//         if(have_contact(i)) continue; // 접점이 있으면

//         path[i] = true;
//         dfs(connected_lines + 1);
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cout.tie(0);
//     cin.tie(0);

//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         int input_line_end;
//         cin >>input_line_end;
//         connecting_lines.push_back(input_line_end);
//     }

//     int max_connected_line = 0;
//     for(int i = 0; i < n; i++){
//         curr_lines = 0;
//         init_path();
//         path[i] = true;
//         dfs(1);
//         max_connected_line = max(max_connected_line, curr_lines);
//     }

//     cout << max_connected_line << "\n";

//     return 0;
// }


// LIS 코드
// 이건 다시 테스트해보자!

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
 
int main()
{
	int n;
	int max_connected_line = 0;
	vector<int> connecting_lines(40001);
	vector<int> lis;

	cin >> n;

    for (int i = 0; i < n; i++) {
		int input_num;
		cin >> input_num;
		connecting_lines.push_back(input_num);
	}

    lis.push_back(INT_MAX);

	for (int i = 0; i < n; i++) {
		int current_num = connecting_lines[i];
		if (lis.back() < current_num) {
			lis.push_back(current_num);
		}
		else {
			*lower_bound(lis.begin(), lis.end(), current_num) = current_num; 
		}
	}

	cout << lis.size() + 1;

	return 0;
}