//
//  [2019 카카오 개발자 겨울 인턴십] 불량 사용자.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/22.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
int answer;
set<string> dup;

bool spell(string idx, vector<string>& user_id, vector<string>& banned_id) {
	int n = idx.size();
	if (n == 0) return true;
	string user = user_id[idx[n-1] - '0'];
	string banned = banned_id[n-1];
	if (user.size() != banned.size()) return false;
	for (int i = 0; i < banned.size(); ++i) {
		if (banned[i] == '*') continue;
		if (banned[i] != user[i]) return false;
	}
	return true;
}

void dfs(int cnt, string idx, vector<bool>& chk,
		 vector<string>& user_id, vector<string>& banned_id) {
	if (!spell(idx, user_id, banned_id)) return;
	if (cnt == banned_id.size()) {
		sort(idx.begin(), idx.end());
		if (!dup.count(idx)) {
			answer++; dup.insert(idx);
		}
		return;
	}
	
	for (int i = 0; i < user_id.size(); ++i) {
		if (chk[i]) continue;
		chk[i] = true;
		dfs(cnt+1, idx + to_string(i), chk, user_id, banned_id);
		chk[i] = false;
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	dup.clear();
	answer = 0;
	vector<bool> chk(user_id.size(), false);
	dfs(0, "", chk, user_id, banned_id);
	return answer;
}

int main() {
	vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
	vector<string> banned_id = {"*rodo", "*rodo", "******"};
	cout << solution(user_id, banned_id) << endl;
	return 0;
}
