//
//  [2019 KAKAO BLIND RECRUITMENT] 무지의 먹방 라이브.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/08.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> food_times, long long k) {
	long long sum = 0;
	map<int, int> mp;
	for (auto& a : food_times) {
		sum += a;
		mp[a]++;
	}
	if (k >= sum) return -1;
	int rest = food_times.size();
	int temp_round = 0;
	// {다 먹을 때까지 남은 초, 개수}
	for (auto& it : mp) {
		long long round = it.first - temp_round;
		if (round * rest <= k) k -= round * rest;
		else {
			k %= rest;
			for (int i = 0; i < food_times.size(); ++i) {
				if (food_times[i] <= temp_round) continue;
				if (k == 0) return i+1;
				--k;
			}
		}
		rest -= it.second;
		temp_round = it.first;
	}
	return -1;
}

int main() {
	vector<int> food_times = {3,1,2};
	int k = 5;
	cout << solution(food_times, k) << endl;
	return 0;
}
