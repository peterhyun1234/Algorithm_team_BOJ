#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int cnt = 1;
    string cur_str, result;
    vector<int> v;

    for (int i = 1; i <= s.length() / 2; i++)
    { // 몇개를 자를 지
        result = "";
        for (int j = 0; j < s.length(); j += i)
        {
            cur_str = s.substr(j, i);

            if (j + i > s.length() || cur_str != s.substr(j + i, i))
            {
                if (cnt != 1)
                    result += to_string(cnt);
                result += cur_str;
                //cout << result << "\n";
                cnt = 1;
            }
            else
                cnt++;
        }
        v.push_back(result.length());
    }

    if (s.length() == 1)
        answer = 1;

    else
        answer = *min_element(v.begin(), v.end());

    return answer;
}