#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cout << endl << "Enter the bit string: ";
	cin >> s;
	cout << endl << "Number of transitions: " << count(s.begin(), s.end(), '1') << endl;
}
