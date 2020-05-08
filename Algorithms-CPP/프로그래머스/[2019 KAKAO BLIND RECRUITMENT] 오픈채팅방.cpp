//
//  [2019 KAKAO BLIND RECRUITMENT] 오픈채팅방.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/08.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
	map<string, string> mp;
	char a[20], b[20], c[20];
	for (int i = 0; i < record.size(); ++i) {
		sscanf(record[i].c_str(), "%s", a);
		if (a[0] == 'E') {
			sscanf(record[i].c_str(), "%s%s%s", a, b, c);
			mp[b] = c;
		}
		else if (a[0] == 'C') {
			sscanf(record[i].c_str(), "%s%s%s", a, b, c);
			mp[b] = c;
		}
	}
	for (int i = 0; i < record.size(); ++i) {
		sscanf(record[i].c_str(), "%s", a);
		if (a[0] == 'E') {
			sscanf(record[i].c_str(), "%s%s%s", a, b, c);
			string temp = mp[b] + "님이 들어왔습니다.";
			answer.push_back(temp);
		}
		else if (a[0] == 'L') {
			sscanf(record[i].c_str(), "%s%s", a, b);
			string temp = mp[b] + "님이 나갔습니다.";
			answer.push_back(temp);
		}
	}
    return answer;
}

int main() {
	vector<string> record = {
		"Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan"
	};
	for (auto& a : solution(record))
		cout << a << endl;
	return 0;
}
