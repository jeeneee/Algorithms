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
    map<string, string> m;
    char a[11], b[11], c[11];
    for (int i = 0; i < record.size(); ++i) {
        sscanf(record[i].c_str(), "%s%s%s", a, b, c);
        if (a[0] == 'E' || a[0] == 'C')
            m[b] = c;
    }
    for (int i = 0; i < record.size(); ++i) {
        sscanf(record[i].c_str(), "%s%s%s", a, b, c);
        if (a[0] == 'E')
            answer.push_back(m[b] + "님이 들어왔습니다.");
        else if (a[0] == 'L')
            answer.push_back(m[b] + "님이 나갔습니다.");
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
