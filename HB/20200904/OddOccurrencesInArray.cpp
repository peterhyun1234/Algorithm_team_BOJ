// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
// 배열에는 홀수 개의 요소
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer;
    int n = A.size();
    vector<bool> num_check(n);
    sort(A.begin(), A.end());
    
    for(int i = 0; i < n-1; i++){
        if(A[i] == A[i + 1]){
            num_check[i] = true;
            num_check[i + 1] = true;
            i++;
        }
    }
    
    for(int i = 0; i < n; i++){
        if(num_check[i] == false){
            answer = A[i];
        }
    }
    return answer;
}