//
//  23-1 변화하는 중간값(RUNNINGMEDIAN).cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/20.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MOD = 20090711;

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % MOD;
		return ret;
	}
};

int runningMedian(int n, RNG rng) {
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int ret = 0;
	for (int cnt = 1; cnt <= n; ++cnt) {
		int x = rng.next();
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(x);
		else
			minHeap.push(x);
		if (!maxHeap.empty() && !minHeap.empty() &&
			maxHeap.top() > minHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % MOD;
	}
	return ret;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		RNG rng(a, b);
		cout << runningMedian(n, rng) << '\n';
	}
	return 0;
}
