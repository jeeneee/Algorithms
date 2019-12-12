#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<int> v;
const int MIN = numeric_limits<int>::min();

int fastMaxSum(const vector<int>& A, int lo, int hi) {
    if (lo == hi) return A[lo];
    int mid = (lo + hi) / 2;
    int left = MIN, right = MIN, sum = 0;
    
    // 두 구간이 붙어있을 때
    for (int i = mid; i >= lo; --i) {
        sum += A[i];
        left = max(left, sum);
    }
    sum = 0;
    for (int i = mid + 1; i <= hi; ++i) {
        sum += A[i];
        right = max(right, sum);
    }
    // 한 구간에 있을 때
    int single = max(fastMaxSum(A, lo, mid),
                     fastMaxSum(A, mid + 1, hi));
    return max(left + right, single);
}

int main() {
    v = {-7, 4, -3, 6, 3, -8, 3, 4};
    cout << fastMaxSum(v, 0, 7) << endl;
}
