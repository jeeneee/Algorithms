//
//  숫자 야구.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/09.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	int i, j;
	for (i = 123; i <= 987; ++i) {
		string cand = to_string(i);
		if (cand[0] == '0' || cand[1] == '0' || cand[2] == '0') continue;
		if (cand[0] == cand[1] || cand[1] == cand[2] || cand[0] == cand[2]) continue;
		for (j = 0; j < baseball.size(); ++j) {
			int strike = 0, ball = 0;
			string num = to_string(baseball[j][0]);
			for (int a = 0; a < 3; ++a) {
				for (int b = 0; b < 3; ++b) {
					if (a == b && cand[a] == num[b]) ++strike;
					if (a != b && cand[a] == num[b]) ++ball;
				}
			}
			if (strike != baseball[j][1] || ball != baseball[j][2])
				break;
		}
		if (j == baseball.size()) ++answer;
	}
    return answer;
}

int main() {
	vector<vector<int>> baseball = {
		{123, 1, 1},
		{356, 1, 0},
		{327, 2, 0},
		{489, 0, 1}
	};
	cout << solution(baseball) << endl;
	return 0;
}
