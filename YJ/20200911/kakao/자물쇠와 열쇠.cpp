#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int insert (int x, int y, int N, vector<vector<int>> board, vector<vector<int>> key){
    int M = key.size();

    //비트논리연산자 이용
    for(int ny = y, a = 0; ny < y + M; ny++, a++){
        for(int nx = x, b = 0; nx < x + M; nx++, b++) {
            board[ny][nx] = board[ny][nx] ^ key[a][b];
            if(!board[ny][nx] && key[a][b]) return -1;
        }
    }

    //해당 자물쇠가 다 들어맞았는지 1의 갯수를 count
    int count = 0;
    for(int ny = M-1; ny < M+N-1; ny++){
        for(int nx = M-1; nx <  N+M-1; nx++){
            if(!board[ny][nx]) count ++;
        }
    }
    return count;

}

vector<vector<int>> rotate(vector<vector<int>> key){
    int s = key.size();
    vector<vector<int>> result(s, vector<int>(s, 0));

    for (int l = 0, a = 0; l < s; l++, a++){
        for(int i = s-1, b = 0; i >= 0 ; i--, b++){
            result[a][b] = key[i][l];
        }
    }
    return result;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size(), M = key.size();
    vector<vector<int>> board(2*M+N-2, vector<int>(2*M+N-2, 0));

    //put lock on the board
    for(int ny = M-1, a = 0; ny < M-1 + N; ny++, a++){
        for(int nx = M-1, b = 0; nx < M-1 + N; nx++, b++) {
            board[ny][nx] = lock[a][b];
        }
    }

    //put key on board with rotation
    for(int i = 0; i < M+N-1; i++){
        for (int l = 0; l < M+N-1; l++){
            vector<vector <int>> nextKey = key;

            for(int d = 0; d < 4; d++)
            {
                if(insert(l, i, N, board, nextKey) == 0) return true;
                nextKey = rotate(nextKey);
            }
        }
    }
    return false;
}

/*
vector<vector<int>> rotate_key(vector<vector<int>> arr) {
    int arr_size = arr.size();
    vector<vector<int>> tmp(arr_size, vector<int>(arr_size, 0));
    
    for (int i = 0; i < arr_size; i ++) {
        for (int j = 0; j < arr[i].size(); j ++) {
            tmp[j][arr_size - i - 1] = arr[i][j];
        }
    }
    
    return tmp;
}

bool can_open(vector<vector<int>> &key, vector<vector<int>> &lock) {
    for (int i = 0; i < lock.size(); i ++) {
        for (int j = 0; j < lock[i].size(); j ++) {
            if (key[i][j] + lock[i][j] != 1) return false;
        }
    }
    return true;
}

bool is_ept(vector<vector<int>> &map) {
    for (int i = 0; i < map.size(); i ++) {
        for (int j = 0; j < map[i].size(); j ++) {
            if (map[i][j] != 0) return false;
        }
    }
    return true;
}

int num_of_this(vector<vector<int>> &map, int num) {
    int cnt = 0;
    for (int i = 0; i < map.size(); i ++) {
        for (int j = 0; j < map[i].size(); j ++) {
            if (map[i][j] == num) cnt ++;
        }
    }
    return cnt;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int num_of_lock_h = num_of_this(lock, 0);
    int num_of_lock_d = num_of_this(lock, 1);
    queue<vector<vector<int>>> Q;
      
    Q.push(key);
    
    while(!Q.empty()) {
        vector<vector<int>> t = Q.front();
        int t_size = t.size();
        bool flag = false;
        Q.pop();
        
        if (num_of_this(t, 1) != num_of_lock_h || num_of_this(t, 0) != num_of_lock_d) continue;
        
        if (is_ept(t)) continue;
        
        for (int m = 0; m < 4; m ++) {
            t = rotate_key(t);
            if (can_open(t, lock)) {
                answer = true;
                flag = true;
                break;
            }
        }
        
        if (flag) break;
        
        // 위 오른 아래 왼 한칸 씩 이동해서 해보기
        for (int i = 0; i < 4; i ++) {
            vector<vector<int>> tmp_map(t_size, vector<int>(t_size, 0));
            int nx, ny;
            for (int j = 0; j < t_size; j ++) {
                for(int k = 0; k < t[j].size(); k ++) {
                    if (t[j][k] == 1) {
                        nx = j + dx[i];
                        ny = k + dy[i];
                        if (nx < 0 || ny < 0 || nx >= t_size || ny >= t_size) continue;
                        tmp_map[nx][ny] = 1;
                    }
                }
            }
            Q.push(tmp_map);
        }
    }
    
    return answer;
}
*/
