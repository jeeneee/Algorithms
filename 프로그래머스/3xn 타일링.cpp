//
//  3xn 타일링.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/07.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	if (n % 2 != 0) return 0;
	vector<long long> dp(n);
	long long temp = 0;
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		temp += (dp[i-4] * 2) % 1000000007;
		dp[i] = (dp[i-2] * 3 + temp) % 1000000007;
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}
