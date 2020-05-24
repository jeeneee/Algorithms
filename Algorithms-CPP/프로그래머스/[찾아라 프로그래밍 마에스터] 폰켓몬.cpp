//
//  [찾아라 프로그래밍 마에스터] 폰켓몬.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/24.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
	set<int> s;
	for (auto& a : nums) s.insert(a);
	return min(s.size(), nums.size() / 2);
}

int main() {
	vector<int> nums = {3,3,3,2,2,2};
	cout << solution(nums) << endl;
	return 0;
}
