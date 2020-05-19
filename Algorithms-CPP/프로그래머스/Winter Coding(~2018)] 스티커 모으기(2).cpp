//
//  Winter Coding(~2018)] 스티커 모으기(2).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/19.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
	int answer = 0;
	int n = sticker.size();
	if (n == 1) return sticker[0];
	vector<int> dp(n, 0);
	// 첫 번째 스티커를 뗄 경우 마지막 스티커는 뗄 수 없다.
	dp[0] = dp[1] = sticker[0];
	for (int i = 2; i < n-1; ++i)
		dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
	answer = max(answer, dp[n-2]);
	
	for (int i = 0; i < n; ++i) dp[i] = 0;
	// 첫 번째 스티커를 떼지 않을 경우 마지막 스티커를 뗄 수 있다.
	dp[0] = 0;
	dp[1] = sticker[1];
	for (int i = 2; i < n; ++i)
		dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
	answer = max(answer, dp[n-1]);
	
	return answer;
}

int main() {
	vector<int> sticker = {14, 6, 5, 11, 3, 9, 2, 10};
	cout << solution(sticker) << endl;
	return 0;
}
