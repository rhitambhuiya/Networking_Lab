#include <bits/stdc++.h>
using namespace std;

vector<int> transmitted;

void drop_packet(int n)
{
    int random = rand() % n;
    cout << endl << "Packet " << transmitted[random] << " dropped..." << endl;
    transmitted.erase(transmitted.begin() + random);
    this_thread::sleep_for(chrono::seconds(1));
}

int main(){
    srand(time(0));
    int buffer_size, packets;
    float limit;
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
            drop_packet(n);
        cout << endl << "Transmitting packet " << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        transmitted.push_back(i);
    }
}