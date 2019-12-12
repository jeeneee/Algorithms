#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> v;
const int MIN = numeric_limits<int>::min();

int fastestMaxSum(const vector<int>& A) {
    int N = A.size(), ret = MIN, psum = 0;
    for (int i = 0; i < N; ++i) {
        psum = max(psum, 0) + A[i];
        ret = max(ret, psum);
    }
    return ret;
}

int main() {
    v = {-7, 4, -3, 6, 3, -8, 3, 4};
    cout << fastestMaxSum(v) << endl;
}
