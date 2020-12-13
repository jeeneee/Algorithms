#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = n/5; i >=0; i--) {
        if ((n - 5 * i) % 3 == 0) {
            cout << i + (n - 5 * i) / 3 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
