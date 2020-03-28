//
//  5658_[모의 SW 역량테스트] 보물상자 비밀번호.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/28.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: string을 시계방향으로 돌리는 문제. 16진법을 10진법으로 변환.
 */
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

string s;
set<int> v;
int n, k;

int hex2dec(string& str) {
	int ret = 0;
	for (int i = 0; i < str.size(); ++i) {
		int num = 0;
		if (0 <= str[i] && str[i] <= '9') num = str[i] - '0';
		else num = str[i] - 'A' + 10;
		ret += num * pow(16.0, str.size() - (i+1));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		v.clear();
		cin >> n >> k >> s;
		for (int i = 0; i < n/4; ++i) {
			string str;
			for (int j = 0; j < n; ++j) {
				str += s[(i+j) % n];
				if (str.size() % (n/4) == 0) {
					v.insert(hex2dec(str));
					str.clear();
				}
			}
		}
		auto it = v.begin();
		for (int i = 0; i < v.size() - k; ++i)
			it++;
		cout << "#" << tc << " " << *it << endl;
	}
	return 0;
}
