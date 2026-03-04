#include <bits/stdc++.h>
using namespace std;

pair<int, int> bin_add(int a, int b, int carry) {
    int sum = a + b + carry;
    if (sum == 0)
        return {0, 0};
    else if (sum == 1)
        return {1, 0};
    else if (sum == 2)
        return {0, 1};
    else
        return {1, 1};
}

int main() {
    int k, m;
    vector<string> data;
    string checksum = "";
    
    cout << "Enter the number of segments: ";
    cin >> k;
    cout << "Enter the number of bits per segment: ";
    cin >> m;
    
    for (int i = 0; i < k; i++) {
        string s;
        cout << "Enter the data block " << (i + 1) << ": ";
        cin >> s;
        
        string str = s.substr(0, m);
        int num_zeroes = m - str.length();
        str.insert(0, num_zeroes, '0'); 
        
        data.insert(data.begin(), str);  
    }
    
    while (data.size() > 1) {
        string d1 = data.back();  
        data.pop_back();          

        string d2 = data.back();  
        data.pop_back();           

        string ans = "";
        int carry = 0;
        
        for (int i = m - 1; i >= 0; i--) {
            char a = d1[i];
            char b = d2[i];
            pair<int, int> res = bin_add(a - '0', b - '0', carry);  
            string sum = to_string(res.first);
            ans.insert(0, sum);
            carry = res.second;
        }

        if (carry == 1) {
            string answer = "";
            for (int i = m - 1; i >= 0; i--) {
                char a = ans[i];
                pair<int, int> res = bin_add(a - '0', 0, carry);  
                string temp = to_string(res.first);
                answer.insert(0, temp);
                carry = res.second;
            }
            data.push_back(answer);
        } else {
            data.push_back(ans);  
        }
    }
    
    string result = data[0];
    
    for (int i = 0; i < m; i++) {
        if (result[i] == '0') 
            checksum += '1';
        else
            checksum += '0';
    }
    
    cout << endl << "CheckSum is: " << checksum;
}
