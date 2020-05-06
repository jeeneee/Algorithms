//
//  [2020 KAKAO BLIND RECRUITMENT] 가사 검색.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int ALPHABET = 26;
int toNumber(char ch) { return ch - 'a'; }

struct TrieNode {
	TrieNode* children[ALPHABET];
	unordered_map<int, int> map;
	TrieNode() {
		fill(children, children + ALPHABET, nullptr);
	}
	~TrieNode() {
		for (int i = 0; i < ALPHABET; ++i) {
			if (children[i])
				delete children[i];
		}
	}
	void insert(const char* key, int len) {
		if (*key == 0) return;
		int next = toNumber(*key);
		if (children[next] == NULL)
			children[next] = new TrieNode();
		map[len]++;
		children[next]->insert(key + 1, len);
	}
	int find(const char* key, int len) {
		int next = toNumber(*key);
		if (children[next] == NULL) return 0;
		if (*key == '?') return map[len];
		if (*(key + 1) == '?') return children[next]->map[len];
		return children[next]->find(key + 1, len);
	}
};

vector<int> solution(vector<string> words, vector<string> queries) {
	TrieNode* root = new TrieNode();
	TrieNode* reversed_root = new TrieNode();
	vector<int> ret;
	
	for (auto& a : words) {
		int size = a.size();
		const char* word = a.c_str();
		root->insert(word, size);
		
		reverse(a.begin(), a.end());
		const char* reversed_word = a.c_str();
		reversed_root->insert(reversed_word, size);
	}
	for (auto& a : queries) {
		int size = a.size();
		if (a[size-1] == '?') {
			const char* word = a.c_str();
			ret.push_back(root->find(word, size));
		} else {
			reverse(a.begin(), a.end());
			const char* reversed_word = a.c_str();
			ret.push_back(reversed_root->find(reversed_word, size));
		}
	}
	return ret;
}

int main() {
	vector<string> words = {
		"frodo", "front", "frost", "frozen", "frame", "kakao"
	};
	vector<string> queries = {
		"fro??", "????o", "fr???", "fro???", "pro?"
	};
	
	vector<int> answer = solution(words, queries);
	for (auto& a : answer)
		cout << a << ' ';
	cout << endl;
	return 0;
}
