//
//  Winter Coding(~2018)] 예산.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/19.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int i;
    sort(d.begin(), d.end());
    for (i = 0; i < d.size(); ++i) {
        if (d[i] > budget) break;
        budget -= d[i];
    }
    answer = i;
    return answer;
}

int main() {
	vector<int> d = {1,3,2,5,4};
	int budget = 9;
	cout << solution(d, budget) << endl;
	return 0;
}
