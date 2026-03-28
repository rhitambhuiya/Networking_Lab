#include <bits/stdc++.h>
#include <thread>

using namespace std;
int main()
{
	int buffer, leak_rate, packets;
	cout << endl << "Enter the buffer size: ";
	cin >> buffer;
	cout << endl << "Enter the leak rate in Mbps: ";
	cin >> leak_rate;
	cout << endl << "Enter the number of packets: ";
	cin >> packets;
	int storage = 0;
	queue<int> bucket;
	
	for(int i = 1; i <= packets; i++)
	{
		int packet_size;
		cout << endl << "Enter the packet size of packet " << i << ": ";
		cin >> packet_size;
		if (storage + packet_size > buffer)
			cout << endl << "Buffer Overflow! Packet " << i << " discarded!" << endl;
		else
		{
			storage += packet_size;
			bucket.push(packet_size);
		}
	}
	
	int leak = leak_rate;
	int i = 1;
	while(!bucket.empty())
	{
		if(leak < bucket.front())
		{	
			leak = leak_rate;
			cout << endl << "Reinitializing..." << endl;
			this_thread::sleep_for(chrono::seconds(2));
			continue;
		}
		leak -= bucket.front();
		int p_size = bucket.front();
		bucket.pop();
		cout << endl << "Packet " << i << " of size " << p_size << " leaked" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		i += 1;
	}
}
