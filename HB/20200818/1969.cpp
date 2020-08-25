// DNA는 서로 다른 4가지의 뉴클레오티드
// Adenine, Thymine, Guanine, Cytosine
// DNA를 이루는 뉴클레오티드의 첫글자를 따서 표현
// Hamming Distance란 길이가 같은 두 DNA가 있을 때, 각 위치의 뉴클오티드 문자가 다른 것의 개수

// n개의 길이가 같은 DNA가 주어져 있을 때
// Hamming Distance의 합이 가장 작은 DNA s를 구하는 것

// 첫 줄에 DNA의 수 N과 문자열의 길이 M

// 첫째 줄에 Hamming Distance의 합이 가장 작은 DNA
// 둘째 줄에는 그 Hamming Distance의 합

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> nucls(n);
    for (int i = 0; i < n; i++)
        cin >> nucls[i];

    int sum_of_hd = 0;
    for (int i = 0; i < m; i++)
    {
        vector<pair<char, int>> each_nucl;
        each_nucl.push_back({'A', 0});
        each_nucl.push_back({'T', 0});
        each_nucl.push_back({'G', 0});
        each_nucl.push_back({'C', 0});

        for (int j = 0; j < n; j++)
        {
            if (nucls[i][j] == 'A')
            {
                each_nucl[0].second++;
            }
            else if (nucls[i][j] == 'T')
            {
                each_nucl[1].second++;
            }
            else if (nucls[i][j] == 'G')
            {
                each_nucl[2].second++;
            }
            else
            {
                each_nucl[3].second++;
            }
        }

        pair<char, int> cnt_max;
        for (int j = 0; j < 4; j++)
        {
            if (cnt_max.second < each_nucl[j].second)
            {
                cnt_max = each_nucl[j];
            }
        }

        sum_of_hd += (n - cnt_max.second);
        cout << cnt_max.first;
    }
    cout << "\n";

    cout << sum_of_hd << "\n";

    return 0;
}