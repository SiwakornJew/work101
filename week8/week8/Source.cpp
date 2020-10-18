#include <iostream>

using namespace std;

int square_root(int num1) {
    long left_part = 0;
    long right_part = num1 / 2 + 1;
    while (left_part <= right_part) {
        long mid = left_part + (right_part - left_part) / 2;
        long result = mid * mid;
        if (result == (long)num1) {
            return (int)mid;
        }
        else if (result > num1) {
            right_part = mid - 1;
        }
        else {
            left_part = mid + 1;
        }
    }
    return (int)right_part;
}



int main() {
    int count;
    cout << "Input Count";
    cin >> count;
    float num[1000];
    for (int x = 0; x < count; x++)
         cin >> num[x];
    for (int x = 0; x < count; x++)
         cout << "\nSquare root of " << num[x] << " = " << square_root(num[x]) << endl;
  


}