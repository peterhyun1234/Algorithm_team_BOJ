#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct node {
    int num;
    string used_register;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; 
    cin >> t;
    while (t--) {
        int a, b;  
        cin >> a >> b;

        bool end_flag = false;
        queue<node> queue;
        vector<int> path(10001);

        queue.push({ a, "" });

        while (!queue.empty() && !end_flag) {
            node curr_node = queue.front();  
            queue.pop();

            if (path[curr_node.num]) continue;
            path[curr_node.num] = 1;

            if (curr_node.num == b) {
                cout << curr_node.used_register << "\n";
                break;
            }

            for (int i = 0; i < 4; i++) {
                node curr_child_node = { 0, curr_node.used_register };
                switch (i) {
                case 0:
                    curr_child_node.num = (curr_node.num * 2) % 10000;
                    curr_child_node.used_register += "D";
                    break;
                case 1:
                    curr_child_node.num = (curr_node.num == 0 ? 9999 : curr_node.num - 1);
                    curr_child_node.used_register += "S";
                    break;
                case 2:
                    curr_child_node.num = (curr_node.num % 1000) * 10 + curr_node.num / 1000;
                    curr_child_node.used_register += "L";
                    break;
                case 3:
                    curr_child_node.num = (curr_node.num / 10) % 1000 + (curr_node.num % 10) * 1000;
                    curr_child_node.used_register += "R";
                    break;
                }
                // queue.push(curr_child_node); 걍 이렇게 하면 시간초과!
                if (!path[curr_child_node.num]) {
                    if (curr_child_node.num == b) {
                        cout << curr_child_node.used_register << "\n";
                        end_flag = true;
                        break;
                    }
                    queue.push(curr_child_node);
                }
            }
        }
    }
    return 0;
}
