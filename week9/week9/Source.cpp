#include<iostream>
using namespace std;
int getSum(int n)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                sum = sum + i;
            else
            {
                sum = sum + i;
                sum = sum + (n / i);
            }
        }
    }
    sum = sum - n;
    return sum;
}
bool checkAbundant(int n)
{
    return (getSum(n) > n);
}
int main()
{
    int n,f,e;
    cout << "INPUT START :";
    cin >> f;
    cout << "INPUT END :";
    cin >> e;
    cout << "--------------------------------------------\n\n";
    for (int j = f; j <= e; j++)
    {
        n = j;
        checkAbundant(n) ? cout << n << " " : cout << "";
    }
    cout << endl;
}