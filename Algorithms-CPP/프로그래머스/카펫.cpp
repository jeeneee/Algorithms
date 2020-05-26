//
//  카펫.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/26.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer(2, 0);
	int sum = brown + yellow;
	int n, m; // 가로, 세로
	for (m = 1; m*m <= sum; ++m) {
		if (sum % m == 0) {
			n = sum / m;
			if ((n + m) * 2 - 4 == brown) {
				answer = { n, m };
				break;
			}
		}
	}
	return answer;
}
