//
//  13458_시험 감독.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, b, c;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i)
		cin >> A[i];
	long long ans = n;
	cin >> b >> c;
	for (auto a : A) {
		a -= b;
		if (a > 0)
			ans += a / c + (a % c > 0);
	}
	cout << ans << endl;
	return 0;
}
