//
//  [2019 KAKAO BLIND RECRUITMENT] 후보키.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/08.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 비트마스크 + 조합 + 집합
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

bool isPartial(vector<int> &vec, int comb){
	for(int i = 0; i < vec.size(); ++i)
		if((vec[i] & comb) == vec[i]) return true;
	return false;
}

int solution(vector<vector<string>> relation) {
	vector<int> ans;
	int n = relation.size();
	int m = relation[0].size();
	for (int i = 1; i < (1<<m); ++i) {
		set<string> s;
		for (int j = 0; j < n; ++j) {
			string now = "";
			for (int k = 0; k < m; ++k)
				if (i & (1<<k)) now += relation[j][k];
			s.insert(now);
		}
		if (s.size() == n && !isPartial(ans, i))
			ans.push_back(i);
	}
	return ans.size();
}

int main() {
	vector<vector<string>> relation = {
		{"100","ryan","music","2"},
		{"200","apeach","math","2"},
		{"300","tube","computer","3"},
		{"400","con","computer","4"},
		{"500","muzi","music","3"},
		{"600","apeach","music","2"}
	};
	cout << solution(relation) << endl;
	return 0;
}
