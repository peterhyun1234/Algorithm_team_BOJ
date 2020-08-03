//
//  1726.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/03.
//  Copyright © 2020 황영준. All rights reserved.
//

#include<iostream>
#include<queue>
using namespace std;
 
int M, N, ans;
int startx, starty, startdir, destx, desty, destdir;
// 로봇의 x좌표, y좌표, 방향
queue <pair<pair<int, int>, int>> robot;
int visited[101][101][5];
int factory[101][101];
 
// 동, 서, 남, 북
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
 
int bfs()
{
    int count = 0;
    while (!robot.empty())
    {
        int qsz = int(robot.size());
 
        while (qsz--)
        {
            int x = robot.front().first.first;
            int y = robot.front().first.second;
            int d = robot.front().second;
            robot.pop();
 
            if (x == destx && y == desty && d == destdir) return count;
 
            // d 방향으로 최대 3칸까지 갈 수 있다.
            int mx = x + dx[d-1];
            int my = y + dy[d-1];
            int md = d;
            int k = 3;
 
            while (k > 0)
            {
                if (mx < 1 || mx > M || my < 1 || my > N) break;
                if (factory[mx][my] == 1) break;
                if (!visited[mx][my][md]) {
                    visited[mx][my][md] = 1;
                    robot.push(make_pair(make_pair(mx, my), md));
                }
                mx += dx[d-1];
                my += dy[d-1];
                k--;
            }
 
            if (d <= 2) md = 3;
            else md = 1;
 
            // 왼쪽/오른쪽 2 방향으로 회전할 수 있다.
            for (int i = 0; i < 2; i++)
            {
                mx = x;
                my = y;
                md += i;
 
                if (visited[mx][my][md]) continue;
                visited[mx][my][md] = 1;
                robot.push(make_pair(make_pair(mx, my), md));
            }
        }
        count++;
    }
    return count;
}
 
int main()
{
    cin >> M >> N;
 
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> factory[i][j];
        }
    }
 
    cin >> startx >> starty >> startdir;
    robot.push(make_pair(make_pair(startx, starty), startdir));
    visited[startx][starty][startdir] = 1;
 
    cin >> destx >> desty >> destdir;
 
    ans = bfs();
 
    cout << ans;
 
    return 0;
}


/*
#include <iostream>
#include <queue>

using namespace std;

struct movement {
    int x;
    int y;
    int dir;
    int cnt;
    movement (int row, int col, int direction, int count) {
        x = row;
        y = col;
        dir = direction;
        cnt = count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int M, N, map[105][105] = { 0 }, chk[105][105][5] = { 0 }, min = 2147000000;
    int start_x, start_y, start_dir, goal_x, goal_y, goal_dir;
    int dx[4] = {-1, 0, 1, 0}; // 북, 동, 남, 서 순서
    int dy[4] = {0, 1, 0, -1};
    queue<movement> Q;
    
    cin >> M >> N;
    
    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> map[i][j];
        }
    }
    
    cin >> start_x >> start_y >> start_dir;
    cin >> goal_x >> goal_y >> goal_dir;
    
    Q.push(movement(start_x - 1, start_y - 1, start_dir, 0));
    chk[start_x - 1][start_y - 1][start_dir] = 1;
    
    while(!Q.empty()) {
        int nx, ny, nnx, nny, nnnx, nnny;
        movement robot = Q.front();
        Q.pop();
        
        if (robot.x == (goal_x - 1) && robot.y == (goal_y - 1)) {
            if (robot.dir == goal_dir) {
                if (robot.cnt < min) min = robot.cnt;
            } else {
                if (robot.dir % 2 == 0) {
                    if (goal_dir == robot.dir - 1) robot.cnt += 2;
                    else robot.cnt += 1;
                } else {
                    if (goal_dir == robot.dir + 1) robot.cnt += 2;
                    else robot.cnt += 1;
                }
                if (robot.cnt < min) {
                    min = robot.cnt;
                }
            }
        }
        
        for (int i = 0; i < 4; i ++) {
            nx = robot.x + dx[i];
            ny = robot.y + dy[i];
            
            int dirrr;
            
            if (i == 0) dirrr = 4;
            else if (i == 1) dirrr = 1;
            else if (i == 2) dirrr = 3;
            else dirrr = 2;
            
            if (map[nx][ny] == 0 && chk[nx][ny][dirrr] == 0 && nx >= 0 && ny >= 0 && nx < M && ny < N) {
                if (dirrr == robot.dir) { // 원래 향하던 방향
                    if (nx == goal_x - 1 && ny == goal_y - 1) {
                        chk[nx][ny][robot.dir] = 1;
                        Q.push(movement(nx, ny, robot.dir, robot.cnt + 1));
                        continue;
                    }
                    nnx = robot.x + dx[i] * 2;
                    nny = robot.y + dy[i] * 2;
                    if (map[nnx][nny] == 0 && chk[nnx][nny][dirrr] == 0 && nnx >= 0 && nny >= 0 && nnx < M && nny < N) {
                        if (nnx == goal_x - 1 && nny == goal_y - 1) {
                            chk[nnx][nny][robot.dir] = 1;
                            Q.push(movement(nnx, nny, robot.dir, robot.cnt + 1));
                            continue;
                        }
                        nnnx = robot.x + dx[i] * 3;
                        nnny = robot.y + dy[i] * 3;
                        if (map[nnnx][nnny] == 0 && chk[nnnx][nnny][dirrr] == 0 && nnnx >= 0 && nnny >= 0 && nnnx < M && nnny < N) {
                            chk[nx][ny][robot.dir] = 1;
                            chk[nnx][nny][robot.dir] = 1;
                            chk[nnnx][nnny][robot.dir] = 1;
                            Q.push(movement(nnnx, nnny, robot.dir, robot.cnt + 1));
                        } else {
                            chk[nx][ny][robot.dir] = 1;
                            chk[nnx][nny][robot.dir] = 1;
                            Q.push(movement(nnx, nny, robot.dir, robot.cnt + 1));
                        }
                    } else {
                        chk[nx][ny][robot.dir] = 1;
                        Q.push(movement(nx, ny, robot.dir, robot.cnt + 1));
                    }
                } else { // 다른 방향
                    int add_cnt = 0;
                    int dirr;
                    
                    if (i == 0) dirr = 4;
                    else if (i == 1) dirr = 1;
                    else if (i == 2) dirr = 3;
                    else dirr = 2;
                    
                    if (robot.dir == 1) {
                        if (i == 3) add_cnt += 2;
                        else add_cnt += 1;
                    } else if (robot.dir == 2){
                        if (i == 1) add_cnt += 2;
                        else add_cnt += 1;
                    } else if (robot.dir == 3) {
                        if (i == 0) add_cnt += 2;
                        else add_cnt += 1;
                    } else {
                        if (i == 2) add_cnt += 2;
                        else add_cnt += 1;
                    }
                    
                    if (nx == goal_x - 1 && ny == goal_y - 1) {
                        chk[nx][ny][dirr] = 1;
                        Q.push(movement(nx, ny, dirr, robot.cnt + add_cnt + 1));
                        continue;
                    }
                    
                    nnx = robot.x + dx[i] * 2;
                    nny = robot.y + dy[i] * 2;
                    if (map[nnx][nny] == 0 && chk[nnx][nny][dirr] == 0 && nnx >= 0 && nny >= 0 && nnx < M && nny < N) {
                        if (nnx == goal_x - 1 && nny == goal_y - 1) {
                            chk[nnx][nny][dirr] = 1;
                            Q.push(movement(nnx, nny, dirr, robot.cnt + add_cnt + 1));
                            continue;
                        }
                        nnnx = robot.x + dx[i] * 3;
                        nnny = robot.y + dy[i] * 3;
                        if (map[nnnx][nnny] == 0 && chk[nnnx][nnny][dirr] == 0 && nnnx >= 0 && nnny >= 0 && nnnx < M && nnny < N) {
                            chk[nx][ny][dirr] = 1;
                            chk[nnx][nny][dirr] = 1;
                            chk[nnnx][nnny][dirr] = 1;
                            Q.push(movement(nnnx, nnny, dirr, robot.cnt + add_cnt + 1));
                        } else {
                            chk[nx][ny][dirr] = 1;
                            chk[nnx][nny][dirr] = 1;
                            Q.push(movement(nnx, nny, dirr, robot.cnt + add_cnt + 1));
                        }
                    } else {
                        chk[nx][ny][dirr] = 1;
                        Q.push(movement(nx, ny, dirr, robot.cnt + add_cnt + 1));
                    }
                }
            }
        }
        
    }
    
    cout << min << '\n';
    
    return 0;
}
*/
