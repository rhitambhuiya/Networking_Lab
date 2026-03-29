#include <bits/stdc++.h>
using namespace std;

vector<pair<char, int>> transmitted;
bool drop_packet(char app)
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

int main(){
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
        char app;
        cout << endl << "Enter the type of packet " << i << " ('M' for Multimedia or 'F' for File Transfer Protocol): ";
        cin >> app;
        bool flag = true;
        if(n + 1 > threshold)
            flag = drop_packet(app);
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