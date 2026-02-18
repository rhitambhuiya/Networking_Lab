#include <iostream>
#include <string>
using namespace std;

int main()
{
	string data, polynomial;
	cout << "Enter the data bitstream: ";
	cin >> data;
	cout << "Enter the generating polynomial: ";
	cin >> polynomial;
	int degree = polynomial.length() - 1;

	data.append(degree, '0');
	for(int i = 0; i < data.length() - degree - 1; i++)
	{
		if(data[i] == '1')
			for(int j = 0; j < degree + 1; j++)
				data[i + j] = (data[i + j] == polynomial[j]) ? '0' : '1';
	}

	cout << endl << "CRC generated: " << data.substr(data.length() - degree);
}