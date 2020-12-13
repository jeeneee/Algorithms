//
//  9506_약수들의 합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> factors(int n) {
	vector<int> ret;
	ret.push_back(1);
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			if (i * i == n)
				ret.push_back(i);
			else {
				ret.push_back(i);
				ret.push_back(n / i);
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (1) {
		int n;
		cin >> n;
		if (n == -1) break;
		vector<int> f = factors(n);
		int sum = 0;
		for (auto& a: f) sum += a;
		if (sum != n)
			cout << n << " is NOT perfect.";
		else {
			cout << n << " = ";
			for (int i = 0; i < f.size(); ++i) {
				cout << f[i];
				if (i != f.size() - 1)
					cout << " + ";
			}
		}
		cout << '\n';
	}
	return 0;
}
