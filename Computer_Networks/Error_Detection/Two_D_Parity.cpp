#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));
    
    cout << "Enter the matrix values (0 or 1):\n";
    for (int i = 0; i < m; i++) {
    	int count = 0;
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            count += matrix[i][j];
        }
        matrix[i][n] = count % 2;
    }
	
	for(int j = 0; j <= n; j++)
	{
		int count = 0;
		for(int i = 0; i < m; i++)
			count += matrix[i][j];
		matrix[m][j] = count % 2;
	}
	
	cout << endl << "Final Parity Matrix: " << endl;
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
			cout << matrix[i][j];
		cout << endl;
	}
}
