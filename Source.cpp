
#include <iostream>
#include <fstream>

using namespace std;

int stringlen(char* ptr);
bool compareString(char* a, char* b);


int main()
{
	char ID[999];
	char password[999];
	char rID[999];
	char rpassword[999];

	fstream file;

	cout << "\tCREATE NEW ACCOUNT" << endl;
	file.open("ID.txt", ios::out);
	cout << "Username : ";
	cin.getline(ID, 999);
	file << ID;
	file.close();
	file.open("PASSWORD.txt", ios::out);
	cout << "Password : ";
	cin.getline(password, 999);
	file << password;
	file.close();

	cout << "\n\n";

	cout << "\tLOGIN" << endl;
	cout << "Username : ";
	cin.getline(ID, 999);
	cout << "Password : ";
	cin.getline(password, 999);

	file.open("ID.txt", ios::in);
	file >> rID;
	file.close();
	file.open("PASSWORD.txt", ios::in);
	file >> rpassword;
	file.close();

	if (compareString(&ID[0], &rID[0]) && compareString(&password[0], &rpassword[0]))
		cout << "\n\tYou're LOGIN";
	else
		cout << "\nIncorrect Username or Password";

	return 0;
}

int stringlen(char* ptr)
{
	int a = 0;
	while (ptr[a] != '\0')
	{
		a++;
	}
	return a;
}

bool compareString(char* a, char* b)
{
	int na = stringlen(&a[0]);
	int nb = stringlen(&b[0]);
	int c = 0, i = 0;
	if (na == nb)
	{
		for (i = 0; i < na; i++)
		{
			if (a[i] == b[i])
				c++;
		}
	}
	if (c == na)
		return true;
	else
		return false;
}
