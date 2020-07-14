// 시간 초과;

#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int start_num, end_num;

    int i, j;

    cin >> start_num >> end_num;

    for(i = start_num; i < end_num + 1; i++){
        for(j = 2; j < i; j++){
            if(i % j == 0) break;
        }
        if(i == j)
            cout << i << "\n";
    }

    return 0;
}