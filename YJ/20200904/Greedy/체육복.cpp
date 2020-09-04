#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> have_clothes(n + 1, 1);
    
    for (int i = 0; i < lost.size(); i ++) {
        have_clothes[lost[i]] --;
    }
    
    for (int i = 0; i < reserve.size(); i ++) {
        have_clothes[reserve[i]] ++;
    }
        
    for (int i = 1; i <= have_clothes.size(); i ++) {
        if (have_clothes[i] == 2 && i > 1 && have_clothes[i - 1] == 0) {
            have_clothes[i] --;
            have_clothes[i - 1] ++;
        }
        if (have_clothes[i] == 2 && i <= n && have_clothes[i + 1] == 0) {
            have_clothes[i] --;
            have_clothes[i + 1] ++;
        }
    }
    
    for (int i = 1; i < have_clothes.size(); i ++) {
        if (have_clothes[i] > 0) answer ++;
    }
    
    return answer;
}
