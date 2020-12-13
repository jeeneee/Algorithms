//
//  Winter Coding(~2018)] 기지국 설치.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/19.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int l = 1, r = 1;
	int coverage = 2 * w + 1;
	for (int i = 0; i < stations.size(); ++i) {
		r = stations[i] - w;
		if (l < r) answer += (r-l+coverage-1)/coverage;
		l = stations[i] + w + 1;
	}
	r = n+1;
	if (l < r) answer += (r-l+coverage-1)/coverage;
    return answer;
}

int main() {
	int n = 16;
	int w = 2;
	vector<int> stations = {9};
	cout << solution(n, stations, w) << endl;
	return 0;
}
