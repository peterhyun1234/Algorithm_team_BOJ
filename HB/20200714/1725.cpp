// 시간 초과

#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    cin >> N;

    vector<int> height(N);

    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    int max_area = N;

    for (int i = 0; i < N; i++) {
        if (height[i] > max_area) {
            max_area = height[i];
        }
    }

    int current_area = height[0];

    int current_height = 0;
    int current_width = 0;

    for (int a = 0; a < N-1; a++) {

        // cout << "session: " << a + 1 << "\n\n";

        current_height = height[a]; // 작은 수

        for (int b = a; b < N; b++) {

            if (current_height > height[b]) {
                current_height = height[b];
                //break;
            }
            
            current_width = b - a + 1;

            current_area = current_height * current_width;

            if (current_area > max_area) {
                max_area = current_area;
            }

            // cout << "current_area: " << current_height << " X " << current_width << "= " << current_height * current_width << "\n";
            // cout << "current_width: " << current_width << "\n";

        }
    }
     

    cout << max_area << "\n";


    return 0;
}