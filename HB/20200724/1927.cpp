#include<iostream>
#include<queue>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < n; i++){ 
        int input_operation; 
        cin >> input_operation;
        if (input_operation == 0) { 
            if (pq.empty())
            {
                cout << "0" << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else {
            pq.push(input_operation); 
        }
    }
    return 0;
}