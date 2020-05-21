//
//  [2019 카카오 개발자 겨울 인턴십] 튜플.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/21.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	vector<int> bracket;
	vector<pair<int, vector<int>>> v;
	int num = 0;
	bool flag = false;
	for (int i = 1; i < s.size()-1; ++i) {
		if (s[i] == '{')
			flag = true;
		else if ('0' <= s[i] && s[i] <= '9')
			num = num * 10 + s[i] - '0';
		else if (s[i] == ',' && flag) {
			bracket.push_back(num);
			num = 0;
		}
		else if (s[i] == '}') {
			bracket.push_back(num);
			num = 0;
			v.push_back( {bracket.size(), bracket} );
			bracket.clear();
			flag = false;
		}
	}
	sort(v.begin(), v.end());
	set<int> chk;
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v[i].second.size(); ++j)
			if (!chk.count(v[i].second[j])) {
				chk.insert(v[i].second[j]);
				answer.push_back(v[i].second[j]);
			}
	return answer;
}

int main() {
	string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	for (auto& a : solution(s))
		cout << a << ' ';
	cout << endl;
	return 0;
}
