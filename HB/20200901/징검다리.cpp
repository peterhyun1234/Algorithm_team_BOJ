#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n)
{
    int answer = 0;
    int degree_of_rocks = rocks.size();
    sort(rocks.begin(), rocks.end());

    int left = 0;
    int right = distance;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int compared_rock_position = 0;
        int removed_stone_num = 0;
        for (int j = 0; j < degree_of_rocks; j++)
        {
            if (rocks[j] - compared_rock_position < mid)
                removed_stone_num++;
            else
                compared_rock_position = rocks[j];
        }
        if (removed_stone_num > n)
            right = mid - 1;
        else
            left = mid + 1;
    }

    answer = right;

    return answer;
}