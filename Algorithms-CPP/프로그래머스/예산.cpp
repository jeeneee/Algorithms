//
//  예산.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/10.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = 0;
    long long sum = 0;
    sort(budgets.begin(), budgets.end());
	for (auto budget: budgets)
		sum += budget;
	if (sum <= M) return budgets[budgets.size()-1];
    
    int lo = 0, hi = 100000;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int total = 0;
		for (int budget: budgets)
			total += min(mid, budget);
		if (total > M) hi = mid - 1;
		else {
			answer = max(answer, mid);
			lo = mid + 1;
		}
	}
    return answer;
}

int main() {
	vector<int> budgets = {120, 110, 140, 150};
	cout << solution(budgets, 485) << endl;
	return 0;
}
