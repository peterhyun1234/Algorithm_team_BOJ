#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    int examiner_num = times.size();

    long long max_time = *max_element(times.begin(), times.end());

    long long left = 1;
    long long right = max_time * (long long)n;
    long long mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        long long acceptable_person = 0;

        for (int i = 0; i < examiner_num; i++)
        {
            acceptable_person += mid / times[i];
        }

        if (acceptable_person >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return answer;
}