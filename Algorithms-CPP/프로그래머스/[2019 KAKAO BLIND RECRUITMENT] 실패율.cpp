//
//  [2019 KAKAO BLIND RECRUITMENT] 실패율.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/08.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, pair<int, int>> pipii;
typedef long long ll;

bool cmp(const pipii& a, const pipii& b) {
    ll temp = (ll)a.second.first * b.second.second -
        (ll)a.second.second * b.second.first;
    if (temp == 0) return a.first < b.first;
    return temp > 0;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pipii> prob;
    sort(stages.begin(), stages.end());
    for (int i = 1, j = 0; i <= N; ++i) {
        while (j < stages.size() && stages[j] < i) j++;
        int cnt = 0;
        for (int k = j; k < stages.size(); ++k)
            if (stages[k] == i) cnt++;
        prob.push_back({ i, { cnt, stages.size() - j } });
    }
    sort(prob.begin(), prob.end(), cmp);
    for (int i = 0; i < prob.size(); ++i)
        answer.push_back(prob[i].first);
    return answer;
}

int main() {
	int n = 4;
	vector<int> stages = {4,4,4,4,4};
	for (auto& a : solution(n, stages))
		cout << a << endl;
	return 0;
}
