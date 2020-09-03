#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;
	sort(routes.begin(), routes.end());
	int temp = routes[0][1];
	for (int i = 1; i < routes.size(); i++) {
        //현재 차보다 뒤차가 먼저나가면 
		if (routes[i][1] <= temp)
			temp = routes[i][1];
        
        //현재 차가 나가는 부분보다 뒤에 차가 들어온다면
		if (routes[i][0] > temp) {
			answer++;
			temp = routes[i][1];
		}
	}
	return answer;
}