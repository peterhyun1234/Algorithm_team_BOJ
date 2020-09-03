#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return true;
    else if (a.first == b.first) return a.second < b.second;
    else return false;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int, int>> correct_num(3, {0, 0});
    correct_num[0].second = 1;
    correct_num[1].second = 2;
    correct_num[2].second = 3;
    
    int number1[5] = {1, 2, 3, 4, 5};
    int number2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int number3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i ++) {
        if (answers[i] == number1[i % 5]) correct_num[0].first ++;
        if (answers[i] == number2[i % 8]) correct_num[1].first ++;
        if (answers[i] == number3[i % 10]) correct_num[2].first ++;
    }
    
    sort(correct_num.begin(), correct_num.end(), cmp);
    
    if (correct_num[0].first != correct_num[1].first) answer.push_back(correct_num[0].second);
    else {
        answer.push_back(correct_num[0].second);
        answer.push_back(correct_num[1].second);
        if (correct_num[1].first == correct_num[2].first) answer.push_back(correct_num[2].second);
    }
    
    return answer;
}
