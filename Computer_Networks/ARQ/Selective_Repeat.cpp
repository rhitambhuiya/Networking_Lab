#include <bits/stdc++.h>
using namespace std;

bool isLost()
{
	srand(time(0));
        return ((double)rand()) / RAND_MAX < 0.5;
}

void selectiveRepeatARQ(int frames, int window)
{
	vector<bool> ack(frames, false);
	int base = 0;
	while(base < frames)
	{
		for(int i = base; i < min(base + window, frames); i++)
		{
			if(!ack[i]){
				cout << "Sending frame " << i << "...";
				if (isLost())
				{
					cout << "Frame lost! Resending later\n";
					this_thread::sleep_for(chrono::seconds(2));
				}
				else
				{
					cout << "Ack received\n";
					ack[i] = true;
					this_thread::sleep_for(chrono::milliseconds(500));
				}
				
			}
		}
		while (base < frames && ack[base])
			base += 1;
	}
}

int main()
{
	int frames, window;
	cout << "Enter the number of frames to transmit and window size: ";
	cin >> frames >> window;
	selectiveRepeatARQ(frames, window);
}
