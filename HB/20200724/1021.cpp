// 직접계산하는 것 한계가 있음 
// : dequeue 했을 때 current_idx와 dest_idx 사이 거리 참고 못함

//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//
//	vector<int> orders(m);
//
//	for (int i = 0; i < m; i++)
//		cin >> orders[i];
//
//	int current_idx = 1;
//	int min_of_operations = 0;
//
//	for (int i = 0; i < m; i++) {
//		if (current_idx <= orders[i]) {
//			int left_degree = (n + current_idx) - orders[i];
//			int right_degree = orders[i] - current_idx;
//
//			if (left_degree < right_degree) { //왼쪽
//				min_of_operations += left_degree;
//				current_idx = orders[i] + 1;
//			}
//			else { //오른쪽
//				min_of_operations += right_degree;
//				current_idx = orders[i] + 1;
//			}
//		}
//		else {
//			int left_degree = (n - current_idx) + orders[i];
//			int right_degree = current_idx - orders[i];
//			if (left_degree < right_degree) { //왼쪽
//				min_of_operations += left_degree;
//				current_idx = orders[i] + 1;
//			}
//			else { //오른쪽
//				min_of_operations += right_degree;
//				current_idx = orders[i] + 1;
//			}
//		}
//		if (current_idx > n)
//			current_idx = current_idx - n;
//
//		n --;
//	}
//
//	cout << min_of_operations << "\n";
//
//	return 0;
//}


#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, m;

int main(void)
{
    cin >> n >> m;

    deque<int> orders;
    for (int i = 1; i <= n; i++)
        orders.push_back(i);

    int min_of_operations = 0;
    for (int i = 0; i < m; i++)
    {
        int dest_idx;
        cin >> dest_idx;

        int curr_idx = 1;

        for (deque<int>::iterator iter = orders.begin(); iter < orders.end(); iter++)
        {
            if (*iter == dest_idx)
                break;
            curr_idx++;
        }

        int left_operations = curr_idx - 1;
        int right_operations = orders.size() - curr_idx + 1;

        if (left_operations < right_operations)
        {
            for (int j = 1; j <= left_operations; j++)
            {
                int poped_num = orders.front();
                orders.pop_front();
                orders.push_back(poped_num);
                min_of_operations++;
            }
            orders.pop_front();
        }
        else
        {
            for (int j = 1; j <= right_operations; j++)
            {
                int poped_num = orders.back();
                orders.pop_back();
                orders.push_front(poped_num);
                min_of_operations++;
            }
            orders.pop_front();
        }

    }

    cout << min_of_operations << endl;
    return 0;
}

