#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int vSize = truck_weights.size();
    int sumWeight = 0;
    int idx = 0;
    vector<int> timer(vSize, 0);

    while (timer[vSize - 1] != bridge_length + 1)
    {
        answer++;
        if (idx < vSize)
        {
            if (sumWeight + truck_weights[idx] <= weight)
            {
                sumWeight += truck_weights[idx];

                idx++;
            }
        }

        for (int i = 0; i < idx; ++i)
        {
            timer[i]++;
            if (timer[i] == bridge_length )
            {
                sumWeight -= truck_weights[i];
            }
        }
    }
    return answer;
}