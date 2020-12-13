//
//  [2018 KAKAO BLIND RECRUITMENT] 자동완성.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Trie {
    Trie* child[26];
    int count;
    bool terminal;
    Trie() : count(0), terminal(false) {
        memset(child, 0, sizeof(child));
    }
    ~Trie() {
        for (int i = 0; i < 26; ++i)
            if (child[i]) delete child[i];
    }
    void insert(const char* key) {
        if (*key == 0) {
            terminal = true;
            return;
        }
        int cur = *key - 'a';
        if (child[cur] == NULL)
            child[cur] = new Trie();
        child[cur]->count++;
        child[cur]->insert(key + 1);
    }
    int find(const char* key, int cnt) {
        int cur = *key - 'a';
        if (*key == 0) return cnt - 1;
        if (child[cur]->count == 1) return cnt;
        return child[cur]->find(key + 1, cnt + 1);
    }
};

int solution(vector<string> words) {
    int answer = 0;
    Trie* root = new Trie();
    for (auto& word : words)
        root->insert(word.c_str());
    for (auto& word : words)
        answer += root->find(word.c_str(), 1);
    return answer;
}
