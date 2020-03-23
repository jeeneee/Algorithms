//
//  1013_Contact.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 정규표현식 regex
 */
#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s; cin >> s;
		cout << (regex_match(s, regex("(100+1+|01)+")) ? "YES" : "NO") << '\n';
	}
	return 0;
}
