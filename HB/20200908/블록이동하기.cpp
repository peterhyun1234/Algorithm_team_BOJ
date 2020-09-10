#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
 
vector<vector<int>> Map;
map<pair<pair<int, int>, pair<int, int>>, int> visited;
int n;
int answer;
 
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
 
int safe(int x, int y)
{
    if(0 <= x && x < n && 0 <= y && y < n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int check(int x1, int y1, int x2, int y2, int order, int shape)
{   
    // 가로
    if(shape == 0)
    {
        if(order == 0 || order == 2)
        {
            if(safe(x1-1, y1) == 0 || safe(x2-1, y2) == 0)
            {
                return 0;
            }
 
            if(Map[x1-1][y1] != 0 || Map[x2-1][y2] != 0)
            {
                return 0;
            }
        }
        else if(order == 1 || order == 3)
        {
            if(safe(x1+1, y1) == 0 || safe(x2+1, y2) == 0)
            {
                return 0;
            }
 
            if(Map[x1+1][y1] != 0 || Map[x2+1][y2] != 0)
            {
                return 0;
            }
        }   
    }
    // 세로
    else
    {
        if(order == 0 || order == 2)
        {
            if(safe(x1, y1-1) == 0 || safe(x2, y2-1) == 0)
            {
                return 0;
            }
 
            if(Map[x1][y1-1] != 0 || Map[x2][y2-1] != 0)
            {
                return 0;
            }
        }
        else if(order == 1 || order == 3)
        {
            if(safe(x1, y1+1) == 0 || safe(x2, y2+1) == 0)
            {
                return 0;
            }
 
            if(Map[x1][y1+1] != 0 || Map[x2][y2+1] != 0)
            {
                return 0;
            }
        }     
    }
 
   return 1; 
} 
 
void BFS()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 1}});
    visited[{{0, 0}, {0, 1}}] = 1;
    visited[{{0, 1}, {0, 0}}] = 1;
    
    while(!q.empty())
    {
        int cnt = q.size();
        
        while(cnt--)
        {
            int x1 = q.front().first.first;
            int y1 = q.front().first.second;
            int x2 = q.front().second.first;
            int y2 = q.front().second.second;
            q.pop();
 
            // (x1, y1), (x2, y2) 순서 유지
            if(x2 < x1)
            {
                int temp = x1;
                x1 = x2;
                x2 = temp;
            }
 
            if(y2 < y1)
            {
                int temp = y1;
                y1 = y2;
                y2 = temp;
            } 
 
            // 도착 지점 종료
            if(x2 == n-1 && y2 == n-1)
            {
                return;
            }
 
            // 이동
            for(int i = 0; i < 4; i++)
            {        
                int xpos1 = x1 + dx[i];
                int ypos1 = y1 + dy[i];
                int xpos2 = x2 + dx[i];
                int ypos2 = y2 + dy[i];
 
                if(safe(xpos1, ypos1) == 1 && safe(xpos2, ypos2) == 1)
                {
                    if(visited[{{xpos1, ypos1}, {xpos2, ypos2}}] == 0 && visited[{{xpos2, ypos2}, {xpos1, ypos1}}] == 0 && Map[xpos1][ypos1] == 0 && Map[xpos2][ypos2] == 0)
                    {
                        visited[{{xpos1, ypos1}, {xpos2, ypos2}}] = visited[{{x1, y1}, {x2, y2}}] + 1;
                        visited[{{xpos2, ypos2}, {xpos1, ypos1}}] = visited[{{x2, y2}, {x1, y1}}] + 1;
 
                        q.push({{xpos1, ypos1}, {xpos2, ypos2}});
                    }
                }       
            }
 
            // 회전
            for(int i = 0; i < 4; i++)
            {
                int xpos1, ypos1, xpos2, ypos2;
 
                // 가로  
                if(abs(y2-y1) == 1)
                {
                    if(check(x1, y1, x2, y2, i, 0) == 0)
                    {
                       continue;   
                    }
 
                    // x1, y1 기준 위로
                    if(i == 0)
                    {
                        xpos1 = x1;
                        ypos1 = y1;
                        xpos2 = x1-1;
                        ypos2 = y1;
                    }
                    // x1, y1 기준 아래로 
                    else if(i == 1)
                    {
                        xpos1 = x1;
                        ypos1 = y1;
                        xpos2 = x1+1;
                        ypos2 = y1;
                    }
                    // x2, y2 기준 위로
                    else if(i == 2)
                    {
                        xpos1 = x2;
                        ypos1 = y2;
                        xpos2 = x2-1;
                        ypos2 = y2;
                    }
                    // x2, y2 기준 아래로
                    else if(i == 3)
                    {
                        xpos1 = x2;
                        ypos1 = y2;
                        xpos2 = x2+1;
                        ypos2 = y2;
                    }
                }
                // 세로 
                else if(abs(x2-x1) == 1)
                {
                    if(check(x1, y1, x2, y2, i, 1) == 0)
                    {
                       continue;   
                    }
 
                    // x1, y1 기준 좌로 
                    if(i == 0)
                    {
                        xpos1 = x1;
                        ypos1 = y1;
                        xpos2 = x1;
                        ypos2 = y1-1;
                    }
                    // x1, y1 기준 우로 
                    else if(i == 1)
                    {
                        xpos1 = x1;
                        ypos1 = y1;
                        xpos2 = x1;
                        ypos2 = y1+1;
                    }
                    // x2, y2 기준 좌로
                    else if(i == 2)
                    {
                        xpos1 = x2;
                        ypos1 = y2;
                        xpos2 = x2;
                        ypos2 = y2-1;
                    }
                    // x2, y2 기준 우로 
                    else if(i == 3)
                    {
                        xpos1 = x2;
                        ypos1 = y2;
                        xpos2 = x2;
                        ypos2 = y2+1;
                    }
                }
 
                if(visited[{{xpos1, ypos1}, {xpos2, ypos2}}] == 0 && visited[{{xpos2, ypos2}, {xpos1, ypos1}}] == 0)
                {
                    visited[{{xpos1, ypos1}, {xpos2, ypos2}}] = visited[{{x1, y1}, {x2, y2}}] + 1;
                    visited[{{xpos2, ypos2}, {xpos1, ypos1}}] = visited[{{x2, y2}, {x1, y1}}] + 1;
 
                    q.push({{xpos1, ypos1}, {xpos2, ypos2}});
                }
            }   
        }
        
        answer++;
    }                               
}
 
int solution(vector<vector<int>> board) 
{
    Map = board;
    n = board.size();
    
    BFS();
    
    return answer;
}