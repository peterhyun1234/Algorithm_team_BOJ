#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int cnt = (brown + 4) / 2;
    int height = 3, width = cnt - 3;
    
    while (true) {
        if ((height - 2) * (width - 2) == yellow) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        } else {
            height ++;
            width --;
        }
    }
    
    return answer;
}
