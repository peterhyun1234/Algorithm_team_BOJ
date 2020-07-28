//// 넣는 건 절댓값으로 넣고, 뺄 때는 원래값으로
// 
//#include <iostream>
//#include <queue>
//#include <cmath>
//
//using namespace std;
//
//struct ads_num {
//    int origin_num;
//    int abs_num;
//};
//
//int main(void) {
//    ios_base::sync_with_stdio(false); 
//    cin.tie(0); 
//    cout.tie(0);
//
//    int n;
//    cin >> n;
//
//    priority_queue<ads_num, vector<ads_num>, greater<ads_num>> pq;
//
//    for(int i = 0; i < n; i++) {
//        int input_num;
//        cin >> input_num;
//        if (input_num == 0) {
//            if (!pq.empty()) {
//                cout << pq.top().origin_num << "\n";
//                pq.pop();
//            }
//            else {
//                cout << "0\n";
//            }
//        }
//        else {
//            ads_num temp_num;
//            temp_num.origin_num = input_num;
//            temp_num.abs_num = abs(input_num);
//            pq.push(temp_num);
//        }
//    }
//    return 0;
//}


#include <iostream>
#include <queue>
#include <cmath>

using namespace std;


int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int i = 0; i < n; i ++) {

        int input_num;
        cin >> input_num;
        if (input_num == 0) {
            if (!pq.empty()) {
                cout << pq.top().second << "\n";
                pq.pop();
            }
            else {
                cout << "0\n";
            }
        }
        else {
            pq.push({ abs(input_num), input_num });
        }
    }

    return 0;
}
