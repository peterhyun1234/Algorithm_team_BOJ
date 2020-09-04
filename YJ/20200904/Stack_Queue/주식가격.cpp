#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int i = 0; i < prices.size(); i ++) {
        if (i == prices.size() - 1) {
            answer.push_back(0);
            break;
        }
        int cnt = 1;
        for (int j = i + 1; j < prices.size() - 1; j ++) {
            if (prices[j] >= prices[i]) cnt ++;
            else
                break;
        }
        answer.push_back(cnt);
    }

    return answer;
}
