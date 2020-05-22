//
//  [2019 카카오 개발자 겨울 인턴십] 징검다리 건너기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/22.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& stones, int k, int num) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); ++i) {
		if (stones[i] <= num) cnt++;
		else cnt = 0;
		if (cnt == k) return false;
	}
	return true;
}

int solution(vector<int> stones, int k) {
	int lo = 987654321, hi = 0;
	for (int i = 0; i < stones.size(); ++i) {
		lo = min(lo, stones[i]);
		hi = max(hi, stones[i]);
	}
	int answer = lo;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (possible(stones, k, mid-1)) {
			answer = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	return answer;
}

int main() {
	vector<int> stones = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
	int k = 3;
	cout << solution(stones, k) << endl;
	return 0;
}
