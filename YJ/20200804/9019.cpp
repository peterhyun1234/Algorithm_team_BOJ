//
//  9019.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/08/02.
//  Copyright © 2020 황영준. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define mod 10000
#define p pair<int, string>
using namespace std;

int visit[mod];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        memset(visit,0,sizeof(visit));
        int st;
        int dest;
        cin >> st >> dest;
        
        queue<p> q;
        q.push({st,""});
        
        while (! q.empty()) {
            int top = q.front().first;
            string operation = q.front().second;
            q.pop();
            
            if( top == dest) {
                cout << operation << endl;
                break;
            }

            int _top = top;
            operation += "D";
            if( ! visit[_top * 2 % mod] )
                q.push( { _top * 2 % mod, operation } );
            visit[ _top * 2 % mod ] = 1;
            operation.pop_back();
            
            _top = _top == 0 ? 9999 : _top - 1;
            operation += "S";
            if( ! visit[_top ] )
                q.push( { _top, operation } );
            visit[ _top ] = 1;
            operation.pop_back();
            
            operation += "L";
            _top = top / 1000;
            _top += top % 1000 * 10;
            if( ! visit[_top ] )
                q.push( {_top, operation } );
            visit[ _top ] = 1;
            operation.pop_back();
            
            operation += "R";
            _top = top % 10;
            _top = (top / 10) + (_top * 1000);
            if( ! visit[_top ] )
                q.push( { _top, operation } );
            visit[ _top ] = 1;
            operation.pop_back();
            
        } // end of while
    } // end of for i
    
    return 0;
}


/*
#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int D(int x) {
    return (x * 2) % 10000;
}

int S(int x) {
    if ((x - 1) != 0) return x - 1;
    else return 9999;
}

int L(int x) {
    int d1, d2, d3, d4;
    d4 = x % 10;
    x /= 10;
    d3 = x % 10;
    x /= 10;
    d2 = x % 10;
    x /= 10;
    d1 = x % 10;
        
    return (((d2 * 10) + d3) * 10 + d4) * 10 + d1;
}

int R(int x) {
    int d1, d2, d3, d4;
    d4 = x % 10;
    x /= 10;
    d3 = x % 10;
    x /= 10;
    d2 = x % 10;
    x /= 10;
    d1 = x % 10;
    
    return (((d4 * 10) + d1) * 10 + d2) * 10 + d3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T, start, target;
    int chk[10100] = { 0 };
    cin >> T;
    
    while(T > 0) {
        queue<pair<int, string> > Q;
        pair<int, string> x;
        
        cin >> start >> target;
                
        int min_cnt = 2147000000;
        string min_str;
        
        Q.push({D(start), "D"});
        Q.push({S(start), "S"});
        Q.push({L(start), "L"});
        Q.push({R(start), "R"});
        
        while(!Q.empty()) {
            x = Q.front();
            Q.pop();
            
            if(chk[x.first] == 1) continue;
            
            string str = x.second;
            string tmp = str;
            
            if (x.first == target && str.size() < min_cnt) {
                min_cnt = int(str.size());
                min_str = str;
                break;
            }
            
            tmp.push_back('D');
            Q.push({D(x.first), tmp});
            tmp = str;
            tmp.push_back('S');
            Q.push({S(x.first), tmp});
            tmp = str;
            tmp.push_back('L');
            Q.push({L(x.first), tmp});
            tmp = str;
            tmp.push_back('R');
            Q.push({R(x.first), tmp});
            
            chk[x.first] = 1;
        }
        
        cout << min_str << '\n';
        memset(chk, 0, sizeof(chk));
        T --;
    }
    
    return 0;
}
*/
