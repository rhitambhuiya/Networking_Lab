#include <bits/stdc++.h>
using namespace std;

void drop_packet(int n, vector<int> transmitted)
{
    int random = rand() % n;
    cout << endl << "Packet " << transmitted[random] << " dropped..." << endl;
    transmitted.erase(transmitted.begin() + random);
    this_thread::sleep_for(chrono::seconds(1));
}

void random_selection(int packets, int threshold)
{
    vector<int> transmitted;
    for(int i = 1; i <= packets; i++)
    {
        int n = transmitted.size();
        if(n + 1 > threshold)
            drop_packet(n, transmitted);
        cout << endl << "Transmitting packet " << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        transmitted.push_back(i);
    }
}

void application_based_selection(int packets, int threshold)
{
    queue<int> transmitted;
    char app;
    cout << endl << "Enter the application type('M' for Multimedia, 'F' for File Transfer): ";
    cin >> app;
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

void priority_based_selection(int packets, int threshold)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 1; i <= packets; i++)
    {
        int priority;
        cout << endl << "Enter the priority of packet " << i << ": ";
        cin >> priority;
        int n = pq.size();
        if(!pq.empty() && n + 1 > threshold){
            pair<int, int> top = pq.top();
            if(priority < top.first)
            {
                cout << endl << "Packet " << i << " dropped..." << endl;
                this_thread::sleep_for(chrono::seconds(1));
                continue;
            }
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

int main()
{
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

    int choice;
    cout << endl << "Enter your choice for packet dropping technique: \n\n1. Random Selection\n2. Application Based Selection\n3. Priority Based Selection\n\n";
    cin >> choice;
    switch(choice)
    {
        case 1: random_selection(packets, threshold);
        break;

        case 2: application_based_selection(packets, threshold);
        break;

        case 3: priority_based_selection(packets, threshold);
        break;

        default: cout << endl << "Wrong Choice!";
    }
}