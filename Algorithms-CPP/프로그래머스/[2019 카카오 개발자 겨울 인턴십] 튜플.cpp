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
	set<int> ss;
	vector<int> v[501];
	int i = 0, j = 0;
	int total = 0;
	for (i = 1; i < s.size() - 1; ++i) {
		if (s[i] == '{') {
			int cnt = 0;
			int temp = 0;
			vector<int> temp_v;
			for (j = i+1; s[j] != '}'; ++j) {
				if (s[j] == ',') {
					cnt++;
					temp_v.push_back(temp);
					temp = 0;
				}
				else temp = temp * 10 + s[j] - '0';
			}
			cnt++;
			temp_v.push_back(temp);
			v[cnt] = temp_v;
			total = max(total, cnt);
			i = j + 1;
		}
	}
	for (int i = 1; i <= total; ++i) {
		for (int j = 0; j < i; ++j) {
			if (ss.count(v[i][j])) continue;
			answer.push_back(v[i][j]);
			ss.insert(v[i][j]);
		}
	}
    return answer;
}

int main() {
	string s = "{{4,2,3},{3},{2,3,4,1},{2,3}}";
	for (auto a : solution(s))
		cout << a << ' ';
	cout << endl;
	return 0;
}
