//
//  Winter Coding(~2018)] 지형 편집.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/20.
//  Copyright © 2020 장우진. All rights reserved.
//
// 이분 탐색
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


long long cost(vector<vector<int>>& land, int h, int P, int Q) {
	int n = land.size();
	long long ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (land[i][j] > h) ret += (long long)(land[i][j] - h) * Q;
			else if (land[i][j] < h) ret += (long long)(h - land[i][j]) * P;
		}
	return ret;
}
 
long long solution(vector<vector<int> > land, int P, int Q) {
	int n = land.size();
	int lo = INT_MAX, hi = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			lo = min(lo, land[i][j]);
			hi = max(hi, land[i][j]);
		}
	int mid = 0;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		if (lo == hi) break;
		long long c1 = cost(land, mid, P, Q);
		long long c2 = cost(land, mid+1, P, Q);
		if (c1 == c2) break;
		else if (c1 < c2) hi = mid;
		else lo = mid+1;
	}
	return cost(land, mid, P, Q);
}

int main() {
	vector<vector<int>> land = {{4,4,3}, {3,2,2}, {2,1,0}};
	int P = 5;
	int Q = 3;
	cout << solution(land, P, Q) << endl;
	return 0;
}
