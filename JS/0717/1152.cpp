#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);

    int count = 0;
    for(int i=0; i<str.length(); i++){
        if (str[i] == ' ') count++;
    }
    if (str[0] == ' ')
        count -= 1;
    if (str[str.length()-1] == ' ')
        count -= 1;

    cout << count + 1;
}
