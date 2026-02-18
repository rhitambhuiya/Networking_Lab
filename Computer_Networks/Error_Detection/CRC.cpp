#include <bits/stdc++.h>
using namespace std;

string XOR(string a, string b)
{
	int len = a.length()
	string res = "";
	for(int i = 0; i < len; i++)
	{
		if(a[i] == b[i])
			res += "0";
		else
			res += "1";
	}
	return res;
}

string data;
cout << "Enter the data stream: ";
cin >> data;

int degree;
cout << "Enter the degree of the polynomial: ";
cin >> degree;

vector<int> p(degree + 1, 0);
for(int i = 0; i < degree + 1; i++)
{
	int inp;
	cout << "Enter the degree of power " << (degree - i - 1) << ": ";
	cin >> inp;
	p[i] = to_string(input % 2);
}

string poly = accumulate(p.begin(), p.end(), string(""));
string segment = data.substr(0, degree + 1);

string temp = XOR(poly, segment);
temp = temp.substr(1, temp.length())

int i = degree;
while(i < data.length())
{
	string res = "";
	temp += data[i];
	if(temp[0] == "0")
		res = temp;
	else
		res = XOR(temp, poly);
	temp = res.substr(1, res.length());
	i += 1;
}

cout << endl << "CRC generated: " << temp;
