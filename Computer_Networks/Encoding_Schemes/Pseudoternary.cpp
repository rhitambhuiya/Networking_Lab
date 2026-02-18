#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cout << endl << "Enter the bit string: ";
	cin >> s;
	int n = s.length();
	int count = 0;
	
	for(int i = 1; i < n; i++)
	{
		if(s[i] == '1' && s[i - 1] == '1')
			continue;
		count++;
	}
	cout << endl << "Number of transitions: " << count;
}
