#include <bits/stdc++.h>
#include <thread>

using namespace std;
int main()
{
	int buffer, packets, token_consumption;
	cout << endl << "Enter the bucket size: ";
	cin >> buffer;
	cout << endl << "Enter the number of packets: ";
	cin >> packets;
	cout << endl << "Enter the token consumption rate: ";
	cin >> token_consumption;
	int i = 1;
	
	int tokens = buffer;
	while(packets > 0)
	{
		if(tokens < token_consumption)
		{
			cout << endl << "Generating tokens... " << endl;
			this_thread::sleep_for(chrono::seconds(1));
			tokens = buffer;
		}
		packets -= 1;
		cout << endl << "Packet " << i << " processed!" << endl;
		tokens -= token_consumption;
		i += 1;
	}
}
