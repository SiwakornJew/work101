#include <iostream>
#include <string>

using namespace std;
int main()
{
	int x[100],NumCount,NumEnd,count=0;
	cout << "Input Count :";
	cin >> NumCount;
	if (NumCount <= 100)
	{
		for (int i = 0; i < NumCount; i++)
		{
			cout << "Input num" << i + 1 << " :";
			cin >> x[i];
		}
		cout << "Sum is : ";
		cin >> NumEnd;		
		for (int i = 0; i < NumCount; i++)
		{
			cout << x[i] << " ";
		}
		cout << "Array pairs whose sum equal to "<<NumEnd;
		for(int i=0;i<NumCount;i++)
			for (int j =i+1; j < NumCount; j++)
			{
				if (x[i] + x[j] == NumEnd)
				{
				cout << "\n" << x[i] << "," << x[j];
				count++;

				}
				
			}
		cout << "\nNumber of pairs whose sum equal to " << NumEnd << " :" << count;
	}
		
	else
	{
		cout << "Error";
	}
	




}