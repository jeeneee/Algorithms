//
//  1305_광고.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/09.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getPartialMatch(const string& N) {
	int m = (int)N.size();
	vector<int> pi(m, 0);
	int j = 0;
	for (int i = 1; i < m; ++i) {
		while (j > 0 && N[i] != N[j])
			j = pi[j-1];
		if (N[i] == N[j])
			pi[i] = ++j;
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	vector<int> pi = getPartialMatch(s);
	cout << n - pi[n-1] << endl;
	return 0;
}
