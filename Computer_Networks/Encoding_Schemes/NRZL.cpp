#include <iostream>
#include <string>
using namespace std;

int main()
{
	string bit_string;
	cout << endl << "Enter the bit string: ";
	cin >> bit_string;
	int n = bit_string.length();
	int count = 0;
	
	for(int i = 1; i < n; i++)
	{
		if(bit_string[i] != bit_string[i - 1])
			count++;
	}
	cout << endl << "Number of transitions: " << count << endl;
}
