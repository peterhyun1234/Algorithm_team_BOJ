#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int point = 0;
    string compare;
    
    for (int i = 0; i < name.size(); i++) compare += "A";
    
    while (compare != name) {
        int next = 0; int left_answer = 0; int right_answer = 0;
        
        for (int i = 0; i < name.size(); i++) {
            if (point + i < name.size()) right_answer = point + i;
            else right_answer = point + i - name.size();
            
            if (point - i >= 0) left_answer = point - i;
            else left_answer = point - i + name.size();
            
            if (compare[right_answer] != name[right_answer]) next = right_answer;
            else if (compare[left_answer] != name[left_answer]) next = left_answer;
            else continue;
            
            answer += i;
            answer += min(name[next] - 'A', 'Z' - name[next] + 1);
            compare[next] = name[next];
            break;
        }
        point = next;
    }
    
    return answer;
}
