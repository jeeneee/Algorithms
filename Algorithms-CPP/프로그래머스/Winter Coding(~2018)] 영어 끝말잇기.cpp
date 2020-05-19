//
//  Winter Coding(~2018)] 영어 끝말잇기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/19.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
	set<string> s;
	int i;
	char prev = words[0][0];
	bool fail = false;
	for (i = 0; i < words.size(); ++i) {
		if (prev != words[i][0] || s.count(words[i])) {
			fail = true;
			break;
		}
		s.insert(words[i]);
		prev = words[i][words[i].size()-1];
	}
	if (!fail) answer[0] = answer[1] = 0;
	else {
		answer[0] = i % n + 1;
		answer[1] = i / n + 1;
	}
    return answer;
}

int main() {
	int n = 3;
	vector<string> words = {
		"tank", "kick", "know", "wheel",
		"land", "dream", "mother", "robot", "tank"
	};
	vector<int> ans = solution(n, words);
	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}
