//
//  [2019 KAKAO BLIND RECRUITMENT] 실패율.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/08.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<double, int>& a, const pair<double, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
	vector<pair<double, int>> prop;
	sort(stages.begin(), stages.end());
	for (int i = 1, j = 0; i <= N; ++i) {
		while (j < stages.size() && stages[j] < i) ++j;
		int cnt = 0;
		for (int k = j; k < stages.size(); ++k)
			if (stages[k] == i) ++cnt;
		if (cnt == 0) prop.push_back( {0, i} );
		else prop.push_back( {(double)cnt/(stages.size()-j), i} );
	}
	sort(prop.begin(), prop.end(), cmp);
	for (auto& a : prop)
		answer.push_back(a.second);
    return answer;
}

int main() {
	int n = 4;
	vector<int> stages = {4,4,4,4,4};
	for (auto& a : solution(n, stages))
		cout << a << endl;
	return 0;
}
