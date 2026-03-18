#include <bits/stdc++.h>
using namespace std;

bool isLost()
{
	srand(time(0));
        return ((double)rand()) / RAND_MAX < 0.5;
}

void stopAndWaitARQ(int frames)
{
	for(int i = 1; i <= frames; i++)
	{
		cout << endl << "Sending frame " << i << "..." << endl;
		if(isLost())
		{
			this_thread::sleep_for(chrono::seconds(2));
			cout << endl << "Frame lost! Resending..." << endl;
			i -= 1;
		}
		else
		{
			this_thread::sleep_for(chrono::milliseconds(500));
			cout << endl << "Acknowledgement Received" << endl;
		}
	}
}

int main()
{
	int frames;
	cout << "Enter the number of frames to transmit: ";
	cin >> frames;
	stopAndWaitARQ(frames);
}
