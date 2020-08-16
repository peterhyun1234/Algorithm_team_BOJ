// 준규는 세계 최고 수준의 암호학자이기 때문에 해빈이에게 암호로 메세지
// 메세지에 항상 영소문자, 온점('.'), 공백 (' ', ASCII코드 32)만

// key값으로는 항상 '0'부터 '9'까지의 숫자만
// 해빈이는 이를 이용해 메세지에 있는 온점과 공백의 위치를 알 수 있다

// 첫 줄에는 암호화 된 메세지의 길이인 정수 N (1 ≤ N ≤ 1000)
// 암호화 된 메세지가 N개의 16진수 정수로

// N개의 문자를 한 줄에 출력한다. 만약 i번째 글자가 문자라면 '-'를, 아니라면 '.'

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string input_str;
        cin >> input_str;
        int hex_num = stoi(input_str, 0, 16);

        if (64 <= hex_num && hex_num <= 95)
        {
            cout << "-";
        }
        else
        {
            cout << ".";
        }
    }

    cout << "\n";

    return 0;
}
