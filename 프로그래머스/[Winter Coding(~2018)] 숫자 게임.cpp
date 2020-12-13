//
//  Winter Coding(~2018)] 숫자 게임.cpp
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

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int i = 0, j = 0;
	for (j = 0; j < B.size(); ++j) {
		if (A[i] < B[j]) {
			++i; ++answer;
		}
	}
    return answer;
}

int main() {
	vector<int> A = {5, 1, 3, 7};
	vector<int> B = {2, 2, 6, 8};
	cout << solution(A, B) << endl;
	return 0;
}
