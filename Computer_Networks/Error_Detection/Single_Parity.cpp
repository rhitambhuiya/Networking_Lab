#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cout << "Enter the bit string: ";
	cin >> s;
	int parity = count(s.begin(), s.end(), '1') & 1;
	
	cout << endl << "The bit string to be transmitted: " << s + to_string(parity);
}
