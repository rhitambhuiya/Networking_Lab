#include <bits/stdc++.h>
using namespace std;

void drop_packet_random(int n, vector<int> &transmitted)
{
    int random = rand() % n;
    cout << endl << "Packet " << transmitted[random] << " dropped..." << endl;
    transmitted.erase(transmitted.begin() + random);
    this_thread::sleep_for(chrono::seconds(1));
}

bool drop_packet_app(char app, vector<pair<char, int>> &transmitted)
{
    if(app == 'F')
        return false;
    int idx = -1; 
    for(int i = 0; i < transmitted.size(); i++)
    {
        if (transmitted[i].first == 'M'){
            idx = i;
            break;
        }
    }
    if(idx == -1)
        return false;
    cout << endl << "Dropping packet " << transmitted[idx].second<< "..." << endl;
    this_thread::sleep_for(chrono::seconds(1));
    transmitted.erase(transmitted.begin() + idx);
    return true;
}

void random_selection(int packets, int threshold)
{
    vector<int> transmitted;
    for(int i = 1; i <= packets; i++)
    {
        int n = transmitted.size();
        if(n + 1 > threshold)
            drop_packet_random(n, transmitted);
        cout << endl << "Transmitting packet " << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
        transmitted.push_back(i);
    }
}

void application_based_selection(int packets, int threshold)
{
    vector<pair<char, int>> transmitted;
    for(int i = 1; i <= packets; i++)
    {
        int n = transmitted.size();
        char app;
        cout << endl << "Enter the type of packet " << i << " ('M' for Multimedia or 'F' for File Transfer Protocol): ";
        cin >> app;
        bool flag = true;
        if(n + 1 > threshold)
            flag = drop_packet_app(app, transmitted);
        if(!flag){
            cout << endl << "Dropping packet " << i << "..." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            continue;
        }
        transmitted.push_back({app, i});
        cout << endl << "Transmitting packet " << i << "..." << endl;
        this_thread::sleep_for(chrono::seconds(1));
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