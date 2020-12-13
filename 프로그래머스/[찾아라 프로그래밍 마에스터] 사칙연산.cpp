//
//  [찾아라 프로그래밍 마에스터] 사칙연산.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/25.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int solution(vector<string> arr) {
	int n = arr.size() / 2 + 1;
	vector<vector<int>> dp_max(n, vector<int>(n, -INF));
	vector<vector<int>> dp_min(n, vector<int>(n, INF));
	for (int i = 0; i < n; ++i)
		dp_max[i][i] = dp_min[i][i] = stoi(arr[i*2]);
	for (int t = 1; t < n; ++t) {
		for (int i = 0; i < n-t; ++i) {
			int j = t + i;
			for (int k = i; k < j; ++k) {
				if (arr[k*2+1] == "+") {
					dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] + dp_max[k+1][j]);
					dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] + dp_min[k+1][j]);
				} else {
					dp_max[i][j] = max(dp_max[i][j], dp_max[i][k] - dp_min[k+1][j]);
					dp_min[i][j] = min(dp_min[i][j], dp_min[i][k] - dp_max[k+1][j]);
				}
			}
		}
	}
	return dp_max[0][n-1];
}

int main() {
	vector<string> arr = {"5", "-", "3", "+", "1", "+", "2", "-", "4"};
	cout << solution(arr) << endl;
	return 0;
}
