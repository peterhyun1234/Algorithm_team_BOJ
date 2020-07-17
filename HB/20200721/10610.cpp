#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string input_num;

    cin >> input_num;
    int input_len = input_num.size();
    int sum = 0;

    vector<int> input_num_vec;

    for (int i = 0; i < input_len; i++) {
        sum += input_num[i] - '0';
        input_num_vec.push_back(input_num[i] - '0');
    }

    sort(input_num_vec.begin(), input_num_vec.end(), greater<>());

    if (input_num_vec[input_len - 1] == 0) {
        if (sum % 3 == 0) {
            for (int i = 0; i < input_len; i++)
                cout << input_num_vec[i];
        }
        else {
            cout << "-1" << "\n";
        }
    }
    else {
        cout << "-1" << "\n";
    }


    return 0;
}