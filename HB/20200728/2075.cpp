// 모든 수는 자신의 한 칸 위에 있는 수보다 크다
// N번째 큰 수를 출력\
// 이렇게 푸는 거 아닌거 같은데... ㅋㅋㅋㅋ 메모리초과 날줄 알았는데
// 원래 방법 찾아보자

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;


// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
    
//     int n;
//     cin >> n;
//     //vector<vector<int>> numbers(n, vector<int>(n));
//     vector<int> numbers(n*n);

//     //for (int i = 0; i < n; i++){
//         for (int j = 0; j < n*n; j++) {
//             cin >> numbers[j];
//         }
//     //}

//     sort(numbers.begin(), numbers.end(), greater<>());

//     cout << numbers[n-1] << "\n";

//     return 0;
// }

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<>> pq;
    int num;
    cin >> num;
    
    for (int i = 0; i < num * num; i++) {
        int tmp;
        cin >> tmp;
        if (pq.size() < num) pq.push(tmp);
        else {
            pq.push(tmp);
            pq.pop();
        }
    }
    
    cout << pq.top() << '\n';
    
    return 0;
}