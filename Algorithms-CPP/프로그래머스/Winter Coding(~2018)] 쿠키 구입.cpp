//
//  Winter Coding(~2018)] 쿠키 구입.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
	int n = cookie.size();
	vector<int> psum(n+1, 0);
	for (int i = 0; i < n; ++i)
		psum[i+1] = psum[i] + cookie[i];
	for (int i = 1; i < n; ++i) {
		for (int j = i+1; j <= n; ++j) {
			int left = i, right = j;
			while (left <= right) {
				int mid = (left + right) / 2;
				int left_sum = psum[mid] - psum[i-1];
				int right_sum = psum[j] - psum[mid];
				if (left_sum == right_sum) {
					answer = max(answer, left_sum);
					break;
				}
				else if (left_sum > right_sum) right = mid - 1;
				else left = mid + 1;
			}
		}
	}
//	for (int m = 1; m < n; ++m) {
//		int a = psum[m]; // 아들 1
//		for (int r = m+1; r <= n; ++r) {
//			int b = psum[r] - a; // 아들 2
//			if (b > a) break;
//			if (answer >= b) continue;
//			for (int l = 0; l < m; ++l)
//				if (b >= a - psum[l]) {
//					if (b == a - psum[l]) answer = b;
//					break;
//				}
//		}
//	}
		
    return answer;
}

int main() {
	vector<int> cookie = {1,1,2,3};
	cout << solution(cookie) << endl;
	return 0;
}
