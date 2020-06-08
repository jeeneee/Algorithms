//
//  단어 변환.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/06/08.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;

void dfs(int idx, int cnt, string target, vector<int>& temp, vector<bool>& visited,
		 vector<vector<int>>& cand, vector<string>& words) {
	if (idx != -1 && words[idx] == target) {
		answer = min(answer, cnt);
		return;
	}
	for (int i = 0; i < temp.size(); ++i) {
		if (visited[temp[i]]) continue;
		visited[temp[i]] = true;
		dfs(temp[i], cnt+1, target, cand[temp[i]], visited, cand, words);
		visited[temp[i]] = false;
	}
}

int solution(string begin, string target, vector<string> words) {
    answer = 987654321;
	bool possible = false;
	for (int i = 0; i < words.size(); ++i)
		if (target == words[i]) possible = true;
	if (!possible) return 0;
	vector<vector<int>> cand(words.size());
	for (int i = 0; i < words.size(); ++i) {
		for (int j = 0; j < words.size(); ++j) {
			if (i == j) continue;
			int cnt = 0;
			for (int k = 0; k < words[i].size(); ++k)
				if (words[i][k] != words[j][k]) ++cnt;
			if (cnt == 1) cand[i].push_back(j);
		}
	}
	vector<int> temp;
	for (int i = 0; i < words.size(); ++i) {
		int cnt = 0;
		for (int k = 0; k < target.size(); ++k)
			if (begin[k] != words[i][k]) ++cnt;
		if (cnt == 1) temp.push_back(i);
	}
	vector<bool> visited(words.size(), false);
	dfs(-1, 0, target, temp, visited, cand, words);
    return answer;
}

int main() {
	vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
	cout << solution("hit", "cog", words) << endl;
	return 0;
}
