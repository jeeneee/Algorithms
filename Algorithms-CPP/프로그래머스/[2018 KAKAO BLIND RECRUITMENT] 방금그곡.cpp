//
//  [2018 KAKAO BLIND RECRUITMENT] 방금그곡.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/09/15.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int calcMinutes(string s) {
	int ret = (s[0] - '0') * 10 * 60 + (s[1] - '0') * 60;
	ret += (s[3] - '0') * 10 + s[4] - '0';
	return ret;
}

string solution(string _m, vector<string> _musicinfos) {
	int n = _musicinfos.size();
    string answer = "(None)";
	string m = "";
	vector<string> musicinfos(n, "");
	for (int i = 0; i < _m.size(); ++i) {
		if (_m[i] == '#') m.back() = tolower(m.back());
		else m += _m[i];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < _musicinfos[i].size(); ++j) {
			if (_musicinfos[i][j] == '#')
				musicinfos[i].back() = tolower(musicinfos[i].back());
			else musicinfos[i] += _musicinfos[i][j];
		}
	int max_mins = 0;
	for (int i = 0; i < n; ++i) {
		istringstream ss(musicinfos[i]);
		vector<string> v;
		string token;
		while (getline(ss, token, ','))
			v.push_back(token);
		int mins = calcMinutes(v[1]) - calcMinutes(v[0]);
		string music = "";
		for (int j = 0; j < mins; ++j)
			music += v[3][j % v[3].size()];
		if (music.find(m) != string::npos) {
			if (mins > max_mins) {
				answer = v[2];
				max_mins = mins;
			}
		}
	}
    return answer;
}

int main() {
	string m = "CC#BCC#BCC#BCC#B";
	vector<string> musicinfos = {
		"03:00,03:30,FOO,CC#B",
		"04:00,04:08,BAR,CC#BCC#BCC#B"
	};
	cout << solution(m, musicinfos) << endl;
	return 0;
}
