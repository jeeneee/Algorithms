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

const int INF = 1e9;
int n, m, answer, targetIdx;
vector<vector<int>> adj;
vector<bool> chk;

void dfs(int idx, int cnt) {
    if (idx == targetIdx) {
        answer = min(answer, cnt);
        return;
    }
    for (int i = 0; i < adj[idx].size(); ++i) {
        int next = adj[idx][i];
        if (chk[next]) continue;
        chk[next] = true;
        dfs(next, cnt + 1);
        chk[next] = false;
    }
}

int solution(string begin, string target, vector<string> words) {
    answer = INF;
    words.insert(words.begin(), begin);
    
    n = words.size();
    m = begin.size();
    
    targetIdx = -1;
    for (int i = 0; i < n; ++i)
        if (words[i] == target) targetIdx = i;
    
    if (targetIdx == -1) return 0;
    
    adj.resize(n);
    chk.resize(n, false);
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < m; ++k)
                if (words[i][k] != words[j][k]) cnt++;
            if (cnt == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    chk[0] = true;
    dfs(0, 0);
    
    if (answer == INF) answer = 0;
    
    return answer;
}
int main() {
	vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
	cout << solution("hit", "cog", words) << endl;
	return 0;
}
