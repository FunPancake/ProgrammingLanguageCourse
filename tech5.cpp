#include <iostream>

using namespace std;

int main() {
    float i = 0;
    float j= 0;
    float k = (j + 13) / 27;

    cout << "Enter a number: ";
    cin >> j;

    while (k < 10) {
        k += 1;
        i = 3 * k - 1;
        cout << "i: " << i << ", j: " << j << ", k: " << k << endl;
    }

    return 0;
}