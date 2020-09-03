#include <string>
#include <vector>

using namespace std;

int answer = 1, kind_size = 0;
vector<pair<int, string>> kind;
vector<bool> chk(kind_size);

int solution(vector<vector<string>> clothes) {
    for (int i = 0; i < clothes.size(); i ++) {
        bool flag = false;
        for (int j = 0; j < kind.size(); j ++) {
            if (clothes[i][1] == kind[j].second) {
                kind[j].first ++;
                flag = true;
                break;
            }
        }
        if (flag) continue;
        kind.push_back({1, clothes[i][1]});
    }

    kind_size = kind.size();

    for (int i = 0; i < kind.size(); i ++) {
        answer *= (kind[i].first + 1);
    }

    return answer - 1;
}
