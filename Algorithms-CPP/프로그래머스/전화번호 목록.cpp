//
//  전화번호 목록.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/29.
//  Copyright © 2020 장우진. All rights reserved.
//
// 트라이 문제
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int toNumber(char ch) { return ch - '0'; }

bool answer;

struct TrieNode {
	TrieNode* children[10];
	bool terminal;
	TrieNode() : terminal(false) {
		memset(children, 0, sizeof(children));
	}
	~TrieNode() {
		for (int i = 0; i < 10; ++i) {
			if (children[i])
				delete children[i];
		}
	}
	void insert(const char* key) {
		if (*key == 0) {
			terminal = true;
			for (int i = 0; i < 10; ++i)
				if (children[i]) answer = false;
		}
		else {
			int cur = toNumber(*key);
			if (children[cur] == NULL)
				children[cur] = new TrieNode();
			if (children[cur]->terminal)
				answer = false;
			children[cur]->insert(key + 1);
		}
	}
};

bool solution(vector<string> phone_book) {
	answer = true;
	TrieNode* root = new TrieNode();
	for (auto& p: phone_book) {
		root->insert(p.c_str());
		if (!answer) break;
	}
	return answer;
}

int main() {
	vector<string> phone_book = { "123","12","1","567","88" };
	cout << solution(phone_book) << endl;
	return 0;
}
