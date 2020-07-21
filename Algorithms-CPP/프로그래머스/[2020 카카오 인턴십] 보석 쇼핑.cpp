//
//  [2020 카카오 인턴십] 보석 쇼핑.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/21.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 전형적인 투포인터 문제.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer{0, 0};
	map<string, int> mp;
	for (auto& gem: gems)
		mp[gem]++;
	int n = gems.size(), m = mp.size();
	int l = 0, r = 0;
	int minLen = 1e7;
	mp.clear();
	mp[gems[0]]++;
	while (l <= r && r < n) {
		if (mp.size() < m) {
			if (r+1 >= n) break;
			mp[gems[++r]]++;
		}
		else {
			if (r - l < minLen) {
				minLen = r - l;
				answer[0] = l+1;
				answer[1] = r+1;
			}
			mp[gems[l]]--;
			if (mp[gems[l]] == 0) mp.erase(gems[l]);
			++l;
		}
	}
    return answer;
}

int main() {
	vector<string> gems = {
		"ZZZ", "YYY"
	};
	for (auto a : solution(gems))
		cout << a << ' ';
	cout << endl;
	return 0;
}
