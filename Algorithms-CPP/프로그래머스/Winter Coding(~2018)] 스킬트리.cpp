//
//  Winter Coding(~2018)] 스킬트리.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(string skill, string skill_tree) {
	int now = 0;
	for (int i = 0; i < skill_tree.size(); ++i) {
		for (int j = 0; j < skill.size(); ++j) {
			if (skill_tree[i] == skill[j]) {
				if (j == now) ++now;
				else return false;
				break;
			}
		}
	}
	return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
	for (auto& s : skill_trees)
		answer += solve(skill, s);
    return answer;
}

int main() {
	string skill = "CBD";
	vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};
	cout << solution(skill, skill_trees) << endl;
	return 0;
}
