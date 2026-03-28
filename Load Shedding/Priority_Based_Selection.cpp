#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int buffer_size, packets;
    float limit;
    cout << endl << "Enter the buffer size: ";
    cin >> buffer_size;
    cout << endl << "Enter the number of packets: ";
    cin >> packets;
    cout << endl << "Enter the threshold limit in percentage: ";
    cin >> limit;
    limit /= 100.0;

    int threshold = int(floor(limit * buffer_size));

    for(int i = 1; i <= packets; i++)
    {
        int priority;
        cout << endl << "Enter the priority of packet " << i << ": ";
        cin >> priority;
        int n = pq.size();
        if(n >= threshold){
            pair<int, int> top = pq.top();
            pq.pop();
            cout << endl << "Packet " << top.second << " dropped..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        pair<int, int> packet = {priority, i};
        pq.push(packet);
        cout << endl << "Transmitting packet " << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}