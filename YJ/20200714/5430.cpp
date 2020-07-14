//
//  5430.cpp
//  BOJprac
//
//  Created by 황영준 on 2020/07/13.
//  Copyright © 2020 황영준. All rights reserved.
//
//
//#include <iostream>
//#include <string>
//#include <deque>
//
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    int T;
//    cin >> T;
//
//    for (int i = 0; i < T; i++) {
//        bool reverse = false;
//        string func;
//        int numOfnum;
//        string arrs;
//        bool breakOuterLoop = false;
//
//        cin >> func;
//        cin >> numOfnum;
//        deque<int> arr(numOfnum);
//        cin >> arrs;
//
//        if (numOfnum == 0) {
//            cout << "error" << '\n';
//            break;
//        }
//
//        for (int j = 0; j < numOfnum; j++) {
//            arr[j] = arrs[(j + 1) * 2 - 1] - '0';
//        }
//
//        for (int k = 0; k < func.size(); k++) {
//
//            if (func.substr(k, 2) == "RR") {
//                k = k + 1;
//            } else{
//                string oper = func.substr(k, 1);
//
//                if (oper == "R") {
//                    reverse = !reverse;
//                } else if (oper == "D") {
//                    if (arr.empty()) {
//                        cout << "error" << '\n';
//                        breakOuterLoop = true;
//                        break;
//                    } else {
//                        if(reverse) arr.pop_back();
//                        else arr.pop_front();
//                    }
//                }
//            }
//        }
//
//        if (breakOuterLoop) continue;
//
//        if (!reverse){
//            cout << '[';
//            for (int m = 0; m < arr.size(); m++) {
//                if (m == arr.size() - 1) cout << arr[m] << ']' << '\n';
//                else cout << arr[m] << ',';
//            }
//        } else {
//            int idx = int(arr.size()) - 1;
//            cout << '[';
//            for (int m = idx; m >= 0; m--) {
//                if (m == 0) cout << arr[m] << ']' << '\n';
//                else cout << arr[m] << ',';
//            }
//        }
//    }
//
//    return 0;
//}
// 맞은거 같은데 왜 틀렸다고 하는지 모르겠음
