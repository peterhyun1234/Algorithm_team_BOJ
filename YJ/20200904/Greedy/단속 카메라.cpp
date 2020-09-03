#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());

    int cam_tmp = routes[0][1];
    for (int i = 0; i < routes.size() - 1; i ++) {
        if (cam_tmp > routes[i][1]) cam_tmp = routes[i][1];
        if (cam_tmp < routes[i + 1][0]) {
            answer ++;
            cam_tmp = routes[i + 1][1];
        }
    }
    
    return answer;
}
