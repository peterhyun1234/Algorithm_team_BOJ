#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(int i =0; i < clothes.size(); i++){
        m[clothes[i][1]] += 1;
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
		//cout << "key : " << it->first << " " << "value : " << it->second << '\n';
        // 얼굴을 선택안한다는 선택지 상의를 선택안하다는 선택지를 각각 만들면
        answer *= it->second + 1;
	}

    return answer - 1;
}