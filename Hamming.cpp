#include <bits/stdc++.h>
using namespace std;

int count_parity(vector<int>& data, int pos)
{
    int XOR = 0;
    for (int i = pos - 1; i < data.size(); i += (pos * 2)) {
        for (int j = i; j < min(i + pos, (int)data.size()); ++j) {
            if (data[j] != -1) {  
                XOR ^= data[j];
            }
        }
    }
    return XOR;
}

int main()
{
    string s;
    cout << "Enter the bitstream: ";
    cin >> s;
    
    int d = s.length();
    reverse(s.begin(), s.end());
    
    int r = 0;
    while ((1 << r) < (r + d + 1)) {
        r += 1;
    }

    vector<int> data(d + r, -1);
    
    for (int i = 0; i < r; ++i) {
        int pos = (1 << i);
        int parity = count_parity(data, pos);
        data[pos - 1] = parity;
    }

    int j = 0;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == -1) {
            if (j < s.length()) {
                data[i] = s[j] - '0';
                j += 1;
            }
        }
    }
    
    reverse(data.begin(), data.end());
    
    cout << endl << "Hamming Coded BitStream: ";
    for (int d: data)
        cout << d;
    cout << endl;
    
    string input;
    cout << endl << "Enter the data received by the receiver: ";
	cin >> input;
	reverse(input.begin(), input.end());
	data.clear();
	for (char c : input)
    		data.push_back(c - '0');


	r = 1;
	int ans = 0;
	while ((1 << r) <= data.size()) {
    		int p = count_parity(data, r);  
    		ans += (p * (1 << (r - 1)));    
    		r++;  
	}

	cout << endl << "Error is at bit: " << ans;
}
