#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string div;
    cout << endl << "Enter the bit string: ";
    cin >> s;
    cout << endl << "Enter the polynomial divisor: ";
    cin >> div;
    s = s + string(div.length() - 1, '0');
    int n = s.length();

    for(int i = 0; i <= n - div.length(); i++)
    {
        if(s[i] == '0')
            continue;
        for(int j = 0; j < div.length(); j++)
            s[i + j] = (s[i + j] == div[j]) ? '0' : '1';
    }

    cout << endl << "CRC generated remainder: " << s.substr(n - div.length() + 1);
}