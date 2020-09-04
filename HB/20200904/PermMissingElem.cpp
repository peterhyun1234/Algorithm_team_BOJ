// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int answer;
    
    sort(A.begin(), A.end());
    int i = 0;
    while(true){
        if(A[i] != i+1){
            answer = i+1;
            break;
        }
        i++;
    }
    
    return answer;
}