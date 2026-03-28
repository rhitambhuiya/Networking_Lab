#include <bits/stdc++.h>
#include <thread>

using namespace std;
int main()
{
	int buffer, packets, token_consumption, token_generation_rate;
	cout << endl << "Enter the bucket size: ";
	cin >> buffer;
	cout << endl << "Enter the number of packets: ";
	cin >> packets;
	cout << endl << "Enter the token consumption rate: ";
	cin >> token_consumption;
	int i = 1;
	cout << endl << "Enter after how many intervals tokens will be refilled: ";
	cin >> token_generation_rate;
	int interval = 0;
	
	int tokens = buffer;
	bool flag;
	while(packets > 0)
	{
		interval += 1;
		if(interval % token_generation_rate == 0)
			tokens = buffer;
		if(tokens < token_consumption && flag)
		{
			cout << endl << "Not enough tokens! Waiting until tokens get refilled..." << endl;
			this_thread::sleep_for(chrono::seconds(2));
			flag = false;
			continue;
		}
		flag = true;
		packets -= 1;
		cout << endl << "Packet " << i << " processed!" << endl;
		this_thread::sleep_for(chrono::seconds(1));
		tokens -= token_consumption;
		i += 1;
	}
}
