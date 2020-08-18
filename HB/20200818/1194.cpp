// https://hibee.tistory.com/193

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 51
#define INF 987654321
using namespace std;

struct node {
    int x,y,cnt,key;
    
    node() { }
    node(int _x,int _y,int _cnt,int _key) : x(_x),y(_y),cnt(_cnt),key(_key) { }
};

int n,m;
char map[MAX][MAX];
bool visited[MAX][MAX][64];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

node s;

void bfs(){
    queue<node> q;
    q.push(s);
    visited[s.x][s.y][s.key] = true;
    
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int key = q.front().key;
        q.pop();
        
        // 출구를 만난 경우 (여러개 일 수도 있음)
        if(map[x][y] == '1'){
            cout << cnt << "\n";
            return;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
            if(map[nx][ny] == '#') continue;
            
            // 열쇠를 만난 경우
            if(map[nx][ny]>='a' && map[nx][ny]<='f'){
                int add_key = key | (1 << (map[nx][ny]-'a'));
                
                if(visited[nx][ny][add_key]) continue;
                
                q.push(node(nx,ny,cnt+1,add_key));
                visited[nx][ny][add_key] = true;
            }
            // 문을 만난 경우
            else if(map[nx][ny]>='A' && map[nx][ny]<='F'){
                int chk_key = key & (1 << (map[nx][ny]-'A'));
                
                if(chk_key==0 || visited[nx][ny][key]) continue;
                
                q.push(node(nx,ny,cnt+1,key));
                visited[nx][ny][key] = true;
            }
            // 나머지 경우
            else{
                if(visited[nx][ny][key]) continue;
                
                q.push(node(nx,ny,cnt+1,key));
                visited[nx][ny][key] = true;
            }
        }
    }
    cout << -1 << "\n";
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            
            if(map[i][j] == '0'){
                s.x = i;
                s.y = j;
            }
        }
    }
    
    memset(visited, false, sizeof(visited));
    bfs();
    
    return 0;
}