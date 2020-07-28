#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int num;
    cin >> num;

    for (int i = 1; i < num; i++) {
        int div_sum = i;
        int pow_num = 0;

        for (int j = 0; j < 7; j++) {
            if ((i / pow(10, j)) < 1) {
                pow_num = j;
                break;
            }
        }
        int tmp = i;

        for (int k = 0; k < pow_num; k++) {
            div_sum += tmp % 10;
            tmp = tmp / 10;
        }

        if (div_sum == num) {
            cout << i << endl;
            return 0;
        }

    }

    cout << 0 << endl;
    return 0;
}
