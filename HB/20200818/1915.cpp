// n×m의 0, 1로 된 배열
// 1로 된 가장 큰 정사각형의 크기
// 가장 큰 정사각형의 넓이

// dfs rotation으로 구현하려고 했지만 실패

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int n, m;
// int rectangular[1000][1000];
// bool path[1000][1000];

// int curr_square = 0;

// int dx[] = {1, 0};
// int dy[] = {0, 1};

// void init_path(){
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             path[i][j] = false;
//         }
//     }
// }

// void dfs(int y, int x, int upper_side, int left_side, int lower_side, int right_side){

//     if(upper_side == lower_side && left_side == right_side && upper_side == left_side){
//         curr_square = max(curr_square, (lower_side + 1)*(right_side + 1));
//     }

//     if()


//     // for(int i = 0 ; i < 2; i ++){
//     //     int nx = x + dx[i];
//     //     int ny = y + dy[i];

//     //     if(nx >= n || ny >= n) continue;
//     //     if(path[ny][nx]) continue;

//     //     if(upper_side >= 1 && i == 1){
//     //         dfs(ny, nx, upper_side, left_side, lower_side, right_side + 1);
//     //     }

//     //     if(upper_side >= 1 && i == 1){
//     //         dfs(ny, nx, upper_side, left_side, lower_side, right_side);
//     //     }
//     // }

// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cout.tie(0);
// 	cin.tie(0);

//     cin >> n >> m;

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             cin >> rectangular[i][j];
//         }
//     }

//     int max_square = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(rectangular[i][j] == 1 &&rectangular[i+1][j] == 1 rectangular[i][j+1] == 1 ){
//                 curr_square = 0;
//                 init_path();
//                 path[i][j] = true;
//                 dfs(i, j, 0, 0, 0, 0);
//                 max_square = max(max_square, curr_square);
//             }else if(rectangular[i][j] == 1){
//                 max_square = 1;
//             }
//         }
//     }

//     cout << max_square << "\n";
// 	return 0;
// }


// dp의 점화식을 세워서 풀생각해보자!

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n, m;
    int a[1001][1001], d[1001][1001];
    int max_square_side;
    string s;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            if (a[i][j] == 1) {
                d[i][j] = 1;
                max_square_side = 1;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if(a[i][j] == 1){
                if (a[i - 1][j] == 1 && a[i - 1][j - 1] == 1 && a[i][j - 1] == 1) {
                    d[i][j] = min(d[i - 1][j - 1], d[i - 1][j]);
                    d[i][j] = min(d[i][j], d[i][j - 1]) + 1;
                }
            }
            max_square_side = max(max_square_side, d[i][j]);
        }
    }

    cout << max_square_side*max_square_side << "\n";

    return 0;
}
