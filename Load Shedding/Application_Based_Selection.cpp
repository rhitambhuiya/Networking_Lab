#include <bits/stdc++.h>
using namespace std;

int main(){
    int buffer_size, packets;
    char app;
    float limit;
    queue<int> transmitted;
    cout << endl << "Enter the application type('M' for Multimedia, 'F' for File Transfer): ";
    cin >> app;
    cout << endl << "Enter the buffer size: ";
    cin >> buffer_size;
    cout << endl << "Enter the number of packets: ";
    cin >> packets;
    cout << endl << "Enter the threshold limit in percentage(0 - 100): ";
    cin >> limit;
    limit /= 100.0;

    int threshold = int(floor(limit * buffer_size));
    for(int i = 1; i <= packets; i++)
    {
        int n = transmitted.size();
        if(n + 1 > threshold)
        {
            if(app == 'M'){
                int top = transmitted.front();
                transmitted.pop();
                cout << endl << "Packet " << top << " dropped..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            else
            {
                cout << endl << "Packet " << i << " dropped..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }
        }
        cout << endl << "Transmitting packet " << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        transmitted.push(i);
    }
}