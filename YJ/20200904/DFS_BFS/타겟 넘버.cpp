#include <string>
#include <vector>

using namespace std;

vector<int> arr;
int answer = 0, people_num, t;

void DFS(int Level, int s) {
    if (Level == people_num) {
        if (s == t)
            answer ++;
    } else {
        DFS(Level + 1, s + arr[Level]);
        DFS(Level + 1, s - arr[Level]);
    }
}

int solution(vector<int> numbers, int target) {
    people_num = numbers.size();
    t = target;
    for (int i = 0; i < numbers.size(); i ++) {
        arr.push_back(numbers[i]);
    }
    DFS(0, 0);
    return answer;
}
