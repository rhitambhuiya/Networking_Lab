#include <bits/stdc++.h>
using namespace std;

int countParity(int pos, vector<int> &data)
{
    int start = pos - 1;
    int count = 0;
    while(start < (int)data.size())
    {   
        for(int i = start; i < min((int)data.size(), (start + pos)); i++)
        {
            if(data[i] != -1)
                count += data[i];
        }
        start += pos * 2;
    }
    return count % 2;
}

int main()
{
    string s;
    cout << "Enter the bit stream: ";
    cin >> s;
    int d = s.length();
    int r = 0;
    while ((1 << r) < (r + d + 1))
        r += 1;
    vector<int> data(r + d, -1);
    reverse(s.begin(), s.end());

    int j = 0;
    for(int i = 0; i < r + d; i++)
    {
        if((i & (i + 1)) == 0) // the indices which are power of 2 are redundant bits, if (i + 1) is a power of 2, then ((i + 1) & i) == 0
            continue;
        data[i] = s[j++] - '0';
    }

    for(int i = 0; i < r; i++)
    {
        data[(1 << i) - 1] = countParity(1 << i, data);
    }

    reverse(data.begin(), data.end());
    cout << endl << "Hamming Coded Bitstream: ";
    for(int bit: data)
        cout << bit;

    string received;
    cout << endl << "Enter the data received at receiver's end: ";
    cin >> received;

    reverse(received.begin(), received.end());
    reverse(data.begin(), data.end());
    j = 0;
    for(int i = 0; i < r + d; i++)
    {
        if((i & (i + 1)) == 0)
            continue;
        data[i] = received[j++] - '0';
    }

    int error_bit = 0;
    for(int i = 0; i < r; i++)
    {
        int p = countParity(1 << i, data);
        error_bit += (1 << i) * p;
    }

    reverse(data.begin(), data.end());
    cout << endl << "Bitstream received by the user: ";
    for(int bit: data)
        cout << bit;

    if(error_bit == 0)
        cout << endl << "No error in transmission";
    else
        cout << endl << "Error in bit " << error_bit;
}