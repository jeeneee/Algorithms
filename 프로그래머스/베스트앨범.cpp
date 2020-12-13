//
//  베스트앨범.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/29.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
	map<string, map<int, set<int>, greater<int>>> mp;
	map<string, int> sum;
	map<int, string, greater<int>> sum_sort;
	for (int i = 0; i < genres.size(); ++i) {
		mp[genres[i]][plays[i]].insert(i);
		sum[genres[i]] += plays[i];
	}
	for (auto it = sum.begin(); it != sum.end(); ++it)
		sum_sort[it->second] = it->first;
	for (auto it = sum_sort.begin(); it != sum_sort.end(); ++it) {
		string genre = it->second;
		int cnt = 0;
		for (auto it2 = mp[genre].begin(); it2 != mp[genre].end(); ++it2) {
			for (auto it3 = it2->second.begin(); it3 != it2->second.end(); ++it3) {
				answer.push_back(*it3);
				if (++cnt >= 2) break;
			}
			if (cnt >= 2) break;
		}
	}
	return answer;
}

int main() {
	vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
	vector<int> plays = {500, 600, 150, 800, 2500};
	for (auto a: solution(genres, plays))
		cout << a << endl;
	return 0;
}
