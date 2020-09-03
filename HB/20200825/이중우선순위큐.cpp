#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    int queue_len = 0;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            int input_num = stoi(operations[i].substr(2));
            max_heap.push(input_num);
            min_heap.push(input_num);
            queue_len++;
        }
        else
        {
            if (queue_len == 0)
            {
                while (!max_heap.empty())
                    max_heap.pop();
                while (!min_heap.empty())
                    min_heap.pop();
            }
            if (operations[i][2] == '1')
            { // delete max
                max_heap.pop();
                queue_len--;
            }
            else
            { // delete min
                min_heap.pop();
                queue_len--;
            }
        }
    }

    answer[0] = max_heap.empty() ? 0 : max_heap.top();
    answer[1] = min_heap.empty() ? 0 : min_heap.top();

    return answer;
}