//
//  타겟 넘버.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/09.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer;

void dfs(int idx, int sum, vector<int>& numbers, int target) {
	if (idx == numbers.size()) {
		if (sum == target) ++answer;
		return;
	}
	dfs(idx+1, sum + numbers[idx], numbers, target);
	dfs(idx+1, sum - numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
	answer = 0;
	dfs(0, 0, numbers, target);
    return answer;
}

int main() {
	cout << solution({1,1,1,1,1}, 3) << endl;
	return 0;
}
