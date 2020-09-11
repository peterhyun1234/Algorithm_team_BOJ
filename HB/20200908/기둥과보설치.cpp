// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// void delete_with(vector<vector<int>> &from, vector<int> deleting_element){
//     int from_size = from.size();
//     for(int i = 0; i < from_size; i++){
//         if(from[i][0] == deleting_element[0] && from[i][1] == deleting_element[1] && from[i][2] == deleting_element[2] ){
//             from.erase(from.begin() + i);
//             return;
//         }
//     }
// }

// // x 기준 오름차순, x가 같으면 y 기준 오름차순
// // x, y가 모두 같은 경우 기둥이 보보다 앞에 오면 됩니다.
// bool cmp(vector<int> a, vector<int> b){
//     if(a[0] < b[0]){
//         return true;
//     }else if(a[0] == b[0]){
//         if(a[1] < b[1]){
//             return true;
//         }else if(a[1] == b[1]){
//             if(a[2] < b[2]){
//                 return true;
//             }else{
//                 return false;
//             }
//         }else{
//             return false;
//         }
//     }else{
//         return false;
//     }
// }

// vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
//     vector<vector<int>> answer;

//     int size_of_frame = build_frame.size();
//     int cur_x;
//     int cur_y;
//     int cur_a;
//     int cur_b;

//     for(int i = 0; i < size_of_frame; i++){
//         cur_x = build_frame[i][0];
//         cur_y = build_frame[i][1];
//         cur_a = build_frame[i][2];
//         cur_b = build_frame[i][3];

//         if(cur_b == 1){ // 구조물 설치
//             answer.push_back({cur_x, cur_y, cur_a});
//         }else{ // 구조물 삭제
//             delete_with(answer, {cur_x, cur_y, cur_a});
//         }
//     }

//     sort(answer.begin(), answer.end(), cmp);

//     for(int i = 0; i < answer.size(); i++){
//         cout << answer[i][0] << answer[i][1] << answer[i][2] << "\n";
//     }

//     return answer;
// }

#include <vector>

using namespace std;

bool column[102][102];
bool beam[102][102];

bool possible_built(int x, int y, int a)
{

    if (a == 0) { // 기둥
        if (y == 1)
            return true;
        if (column[x][y - 1])
            return true;
        if (beam[x - 1][y])
            return true;
        if (beam[x][y])
            return true;
    }
    else {
        if (column[x][y - 1])
            return true;
        if (column[x + 1][y - 1])
            return true;
        if (beam[x + 1][y] && beam[x - 1][y])
            return true;
    }

    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x, y, a, b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];
        x++;
        y++;

        if (a == 0 && b == 1) { // 기둥 설치
            if (possible_built(x, y, a))
            {
                column[x][y] = 1;
            }
        }
        else if (a == 1 && b == 1) { // 보 설치
            if (possible_built(x, y, a))
            {
                beam[x][y] = 1;
            }
        }
        else if (a == 0 && b == 0) { // 기둥 삭제

            if (column[x][y + 1] && !possible_built(x, y + 1, a)) continue;
            if (beam[x][y + 1] && !possible_built(x, y + 1, a)) continue;
            if (beam[x - 1][y + 1] && y < n && !possible_built(x - 1, y + 1, a)) continue;

            column[x][y] = 0;
        }
        else { // 보 삭제

            if (column[x][y] && !possible_built(x, y, a)) continue;
            if (column[x + 1][y] && !possible_built(x + 1, y, a)) continue;
            if (beam[x - 1][y] && !possible_built(x - 1, y, a)) continue;
            if (beam[x + 1][y] && !possible_built(x + 1, y, a)) continue;

            beam[x][y] = 0;
        }
    }

    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            if (column[i][j])
            {
                answer.push_back({i - 1, j - 1, 0});
            }

            if (beam[i][j])
            {
                answer.push_back({i - 1, j - 1, 1});
            }
        }
    }

    return answer;
}