#include <bits/stdc++.h>
using namespace std;

bool isLost()
{
	srand(time(0));
        return ((double)rand()) / RAND_MAX < 0.5;
}

void goBackNARQ(int frames, int window)
{
	int base = 0;
	while(base < frames){
	int i;
	cout << "Sending frame: ";
	for(i = base; i < min(base + window, frames); i++)
		cout << i << " ";
	cout << endl;
	for(i = base; i < min(base + window, frames); i++)
	{
		if (isLost())
		{
			cout << "Frame " << i << " lost! Resending from frame " << i << endl;
			this_thread::sleep_for(chrono::seconds(2));
			break;
		}
		else
		{
			cout << "Ack received from frame " << i << endl;
			this_thread::sleep_for(chrono::milliseconds(500));
		}
	}
	base = i;
}
}

int main()
{
	int frames, window;
	cout << "Enter the number of frames to transmit and window size: ";
	cin >> frames >> window;
	goBackNARQ(frames, window);
}
