#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Trie {
	Trie* child[26];
	unordered_map<int, int> map;
	Trie() {
		for (int i = 0; i < 26; ++i)
			child[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 26; ++i)
			if (child[i])
				delete child[i];
	}
	void insert(const char* key, int len) {
		if (*key == 0) return;
		int cur = *key - 'a';
		if (child[cur] == nullptr)
			child[cur] = new Trie();
		map[len]++;
		child[cur]->insert(key + 1, len);
	}
	int find(const char* key, int len) {
		int cur = *key - 'a';
		if (child[cur] == nullptr) return 0;
		if (*key == '?') return map[len];
		if (*(key + 1) == '?') return child[cur]->map[len];
		return child[cur]->find(key + 1, len);
	}
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
	Trie* root = new Trie();
	Trie* reversed_root = new Trie();
	for (auto& w : words) {
		root->insert(w.c_str(), w.size());
		reverse(w.begin(), w.end());
		reversed_root->insert(w.c_str(), w.size());
	}
	for (auto& q : queries) {
		if (q[q.size()-1] == '?')
			answer.push_back(root->find(q.c_str(), q.size()));
		else {
			reverse(q.begin(), q.end());
			answer.push_back(reversed_root->find(q.c_str(), q.size()));
		}
	}
    return answer;
}

int main() {
	vector<string> words = {
		"frodo", "front", "frost", "frozen", "frame", "kakao"
	};
	vector<string> queries = {
		"fro??", "????o", "fr???", "fro???", "pro?"
	};
	for (auto a : solution(words, queries))
		cout << a << endl;
	return 0;
}
