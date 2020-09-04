// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    int n = A.size();
    for(int i = 0 ; i < K; i++){
        int cur_num = A.back();
        A.pop_back();
        A.insert(A.begin(), cur_num);
    }
    
    return A;
}