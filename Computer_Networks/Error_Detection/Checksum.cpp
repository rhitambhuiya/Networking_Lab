#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, k;
    cout << endl << "Enter the no. of bit segments: ";
    cin >> m;
    cout << endl << "Enter the no. of bits in each segment: ";
    cin >> k;

    vector<vector<int>> grid(m, vector<int>(k, -1));
    for(int i = 0; i < m; i++)
    {
        cout << endl << "Enter the bits of segment(put space between bits) " << (i + 1) << ": ";
        for(int j = 0; j < k; j++)
            cin >> grid[i][j];
    }

    vector<int> temp(k, 0);
    for(int j = 0; j < k; j++)
        temp[j] = grid[0][j];

    for(int i = 1; i < m; i++)
    {
        int carry = 0;
        for(int j = k - 1; j >= 0; j--)
        {
            int sum = grid[i][j] + temp[j] + carry;
            carry = sum / 2;
            sum %= 2;
            temp[j] = sum;
        }
        if(carry)
        {
            for(int j = k - 1; j >= 0; j--)
            {
                int sum = temp[j] + carry;
                carry = sum / 2;
                sum %= 2;
                temp[j] = sum;
            }
        }
    }

    cout << endl << "Checksum is: ";
    for(int i = 0; i < k; i++)
        cout << (temp[i] ^ 1);
}