// 일부 숫자 버튼이 고장
// 리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다.
// 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.
//수빈이가 지금 보고 있는 채널은 100번

// 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>

using namespace std;

int min_btn_push = INT_MAX;
int n, m;

vector<int> btn(10);

void find_min_push(string pushing_number) {
    for(int i = 0; i < 10; i++) {
	    if(!btn[i]) {
	        string temp_pushing_number = pushing_number + (char)i;
	        min_btn_push = min(min_btn_push, abs(n - stoi(temp_pushing_number)) + temp_pushing_number.size());

    	    // if(stoi(temp_pushing_number) < 500000) { // 메모리 초과
	    	//     find_min_push(temp_pushing_number);
	        // }

            if(temp_pushing_number.size() < 6) { // 메모리 초과 해결
	    	    find_min_push(temp_pushing_number);
	        }
	    }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    min_btn_push = min(min_btn_push, abs(100 - n)); // 이닛은 걍 플마로 

    for(int i = 0; i < m; i++) {
        int faulted_btn;
    	cin >> faulted_btn;
	    btn[faulted_btn] = 1;
    }
    
    find_min_push("");
    cout << min_btn_push << "\n";

    return 0;
}
