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
		if(s[i] == '0' && s[i - 1] == '0')
			continue;
		count++;
	}
	cout << endl << "Number of transitions: " << count << endl;
}
