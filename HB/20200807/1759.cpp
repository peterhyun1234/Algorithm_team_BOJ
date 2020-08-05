// 암호는 서로 다른 L개의 알파벳 소문자들로 구성
// 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성
// 알파벳이 암호에서 증가하는 순서로 배열
// abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int l, c;
char alphabets[20];

void dfs(int idx, string security_str, int consonants, int vowels)
{
    if (security_str.size() == l)
    {
        if (consonants < 2 || vowels < 1)
            return;

        cout << security_str << "\n";
    }

    for (int i = idx; i < c; i++)
    {
        if (alphabets[i] == 'a' || alphabets[i] == 'e' || alphabets[i] == 'i' || alphabets[i] == 'o' || alphabets[i] == 'u')
            dfs(i + 1, security_str + alphabets[i], consonants, vowels + 1);
        else
            dfs(i + 1, security_str + alphabets[i], consonants + 1, vowels);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> l >> c;

    for (int i = 0; i < c; i++)
        cin >> alphabets[i];

    sort(alphabets, alphabets + c);

    dfs(0, "", 0, 0);

    return 0;
}


