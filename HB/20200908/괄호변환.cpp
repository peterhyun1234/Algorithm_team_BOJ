#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_complete_string(string s)
{
    stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
        char curr_char = s[i];
        if (curr_char == '(')
        {
            stack.push(curr_char);
        }
        else if (curr_char == ')')
        {
            if (stack.empty())
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }
    }

    if (stack.empty())
        return true;
    else
        return false;
}

string find_complete_string(string p)
{
    if (p == "")
        return "";

    string u = "";
    string v = "";
    string result = "";

    int start_cnt = 0;
    int end_cnt = 0;
    int index = 0;

    //2번 조건
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
        {
            start_cnt++;
        }
        else
        {
            end_cnt++;
        }
        index++;

        if (start_cnt == end_cnt)
            break;
    }

    //u와 v로 나누다.
    u += p.substr(0, index);
    v += p.substr(index);

    //3번 조건
    if (is_complete_string(u))
    {
        result += u;
        result += find_complete_string(v);
    }
    else
    {
        //4번 조건

        //4-1
        result = "(";
        //4-2
        result += find_complete_string(v);
        //4-3
        result += ")";

        //4-4
        u = u.substr(1, u.size() - 2);

        for (int i = 0; i < u.size(); i++)
        {
            if (u[i] == '(')
            {
                result += ")";
            }
            else
            {
                result += "(";
            }
        }
    }

    //4-5
    return result;
}

string solution(string p)
{
    string answer = "";

    answer = find_complete_string(p);

    return answer;
}
