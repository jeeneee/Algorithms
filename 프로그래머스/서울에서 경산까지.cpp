//
//  서울에서 경산까지.cpp
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

int solution(int K, vector<vector<int>> travel) {
	int n = travel.size();
	int answer = 0;
	vector<vector<int>> dp(n, vector<int>(100001, 0));
	dp[0][travel[0][0]] = travel[0][1];
	dp[0][travel[0][2]] = travel[0][3];
	for (int i = 1; i < n; ++i) {
		for (int k = 0; k < K; ++k) {
			if (dp[i-1][k] == 0) continue;
			if (k + travel[i][0] <= K) {
				int &ref = dp[i][k+travel[i][0]];
				ref = max(ref, dp[i-1][k] + travel[i][1]);
				answer = max(answer, ref);
			}
			if (k + travel[i][2] <= K) {
				int &ref = dp[i][k+travel[i][2]];
				ref = max(ref, dp[i-1][k] + travel[i][3]);
				answer = max(answer, ref);
			}
		}
	}
	return answer;
}

int main() {
	vector<vector<int>> travel = {
		{500, 200, 200, 100},
		{800, 370, 300, 120},
		{700, 250, 300, 90}
	};
	cout << solution(1650, travel) << endl;
	return 0;
}
