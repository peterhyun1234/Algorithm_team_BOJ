// 화학식에서 괄호 안에 들어가는 반례있음!

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
// 	cout.tie(0);

// 	string input_line;
// 	cin >> input_line;

// 	int idx = 0;
// 	int chemical_sum = 0;
// 	int linelen = input_line.size();

// 	while (idx <= linelen) {
// 		if (input_line[idx] == 'H') {
// 			idx = idx + 2;
// 			if (input_line[idx] == '(' || idx == linelen)
// 				chemical_sum += 1;
// 			else
// 				chemical_sum += 1 * (input_line[idx] - '0');
// 		}
// 		else if (input_line[idx] == 'C') {
// 			idx = idx + 2;
// 			if (input_line[idx] == '(' || idx == linelen)
// 				chemical_sum += 12;
// 			else
// 				chemical_sum += 12 * (input_line[idx] - '0');
// 		}
// 		else if (input_line[idx] == 'O') {
// 			idx = idx + 2;
// 			if (input_line[idx] == '(' || idx == linelen)
// 				chemical_sum += 16;
// 			else
// 				chemical_sum += 16 * (input_line[idx] - '0');
// 		}
// 		else {
// 			idx++;
// 		}
// 	}

// 	cout << chemical_sum << "\n";

// 	return 0;
// }

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int stack[100], st_cnt, tmp;
    string input_line;
    cin >> input_line;
    int linelen = input_line.size();

    for (int i = 0; i < linelen; ++i) {
        char c = input_line[i];
 
        if (c == 'H') {
            tmp = 1;
            stack[st_cnt] += 1;
        }
        else if (c == 'C') {
            tmp = 12;
            stack[st_cnt] += 12;
        }
        else if (c == 'O') {
            tmp = 16;
            stack[st_cnt] += 16;
        }
            
 
        else if (c == '(')
            stack[++st_cnt] = 0;
        else if (c == ')') {
            tmp = stack[st_cnt--];
            stack[st_cnt] += tmp;
        }
 
        else if ('1' < c && c <= '9')
            stack[st_cnt] += tmp * (c - '1');
    }
    cout << stack[0] << "\n";
    return 0;
}
