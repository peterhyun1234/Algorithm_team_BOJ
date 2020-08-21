// 문자열에 폭발 문자열을 심어 놓았다
// 폭발 문자열이 폭발하면 그 문자는 문자열에서 사라지며, 남은 문자열은 합쳐지게
//
// 1. 문자열이 폭발 문자열을 포함하고 있는 경우에, 모든 폭발 문자열이 폭발하게 된다. 남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.
// 2. 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
// 3. 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.

// 남아있는 문자가 없는 경우 => FRULA 출력

// 로직은 간단한데 시간초과가 관건일듯!

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input_str, bomb_str;
    vector<char> result;

    cin >> input_str >> bomb_str;

    for (int i = 0; i < input_str.size(); i++)
    {
        result.push_back(input_str[i]);

        if (result.size() < bomb_str.size()) continue;

        if (result[result.size() - 1] == bomb_str[bomb_str.size() - 1])
        {
            bool bomb_check = true;
            for (int j = 2; j <= bomb_str.size(); j++)
            {
                if (result[result.size() - j] != bomb_str[bomb_str.size() - j])
                {
                    bomb_check = false;
                }
            }

            if (bomb_check)
            {
                result.erase(result.end() - bomb_str.size(), result.end());
            }
        }
    }

    if (result.size() == 0)
    {
        cout << "FRULA";
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i];
        }
    }

    return 0;
}