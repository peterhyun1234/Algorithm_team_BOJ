// 시리얼 번호는 알파벳 대문자 (A-Z)와 숫자 (0-9)
// A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
// 만약 서로 길이가 같다면, A의 모든 자리수의 합과 B의 모든 자리수의 합
// 사전순으로 비교한다. 숫자가 알파벳보다 사전순으로 작다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct serial_num
{
    string serial_num_str;
    int len;
    int sum = 0;
}

bool cmp(serial_num a, serial_num b)
{
    if (a.len > b.len)
    {
        return false;
    }
    else if (a.len == b.len)
    {
        if (a.sum > b.sum)
        {
            return false;
        }
        else if (a.sum == b.sum)
        {
            return a.serial_num_str > b.serial_num_str;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<serial_num> serial_nums;

    for (int i = 0; i < n; i++)
    {
        string input_str;
        cin >> input_str;
        int cur_sum = 0;
        int cur_len = input_str.length();
        for (int j = 0; j < cur_len; j++)
        {
            if (input_str[j] > 10)
            {
                cur_sum += input_str[j];
            }
        }
        serial_nums.push_back({input_str, cur_len, cur_sum});
    }

    sort(serial_nums.begin(), serial_nums.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << serial_nums[i] << "\n";
    }

    return 0;
}