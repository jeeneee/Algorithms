#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 5000001;
int val[MAX], idx[MAX];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, l, x;
	int i = 1, j = 1;
	cin >> n >> l;
	for (int k = 1; k <= n; ++k) {
		while (i < j && idx[i] <= k - l) ++i;
		cin >> x;
		while (i < j && val[j - 1] >= x) --j;
		val[j] = x;
		idx[j++] = k;
		cout << val[i] << ' ';
	}
	cout << '\n';
	return 0;
}