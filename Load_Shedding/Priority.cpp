#include <bits/stdc++.h>
using namespace std;

int main()
{
	int buffer_size, count, threshold;
	char app;
	cout << "Enter the buffer size: ";
	cin >> buffer_size;
	cout << "Enter the no. of packets: ";
	cin >> count;
	
	vector<int> priority(count);
	
	for(int i = 0; i < packets; i++)
	{
		cout << "Enter the priority of packet " << (i + 1) << ": ";
		int p;
		cin >> p;
		priority[i] = p;
	}
	
	while (packets > threshold)
	{
		if(app == 'M')
		
			cout << endl << "Packet " << (i + 1) << " discarded" << endl;
		
		else
			cout << endl << "Packet " << (n - i - 1) << " discarded" << endl;
		i += 1;
		packets -= 1;
	}
}
