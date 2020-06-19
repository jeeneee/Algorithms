//
//  도둑질.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/19.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    int answer = 0;
    vector<int> dp(n-1, 0);
	vector<int> dp2(n, 0);
	dp[0] = money[0];
	dp[1] = money[0];
	dp2[0] = 0;
	dp2[1] = money[1];
	for (int i = 2; i < n-1; ++i)
        dp[i] = max(dp[i-1], dp[i-2] + money[i]);
    for (int i = 2; i < n; ++i)
		dp2[i] = max(dp2[i-1], dp2[i-2] + money[i]);
	answer = max(dp[n-2], dp2[n-1]);
    return answer;
}

int main() {
	cout << solution({1,2,3,1}) << endl;
	return 0;
}
