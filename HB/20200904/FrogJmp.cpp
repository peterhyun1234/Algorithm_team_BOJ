// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
    int answer;
    int remainder = (Y-X)%D;
    if(!remainder){
        answer = (Y-X)/D;
    }
    else{
        answer = (Y-X)/D + 1;
    }
    
    return answer;
}