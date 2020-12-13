//
//  1684_같은 나머지.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/22.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 같은 수가 나온다면 하나만 저장해야 한다.
 모두 같은 수가 나오지 않는다는 전제 하에.
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n), v;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (int i = 0; i+1 < n; ++i)
		if (arr[i+1] - arr[i] != 0)
			v.push_back(abs(arr[i+1] - arr[i]));
	int ans = v[0];
	for (int i = 1; i < v.size(); ++i)
		ans = gcd(ans, v[i]);
	cout << ans << endl;
	return 0;
}
