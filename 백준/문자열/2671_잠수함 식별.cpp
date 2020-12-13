//
//  2671_잠수함 식별.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
	string s;
	cin >> s;
	cout << (regex_match(s, regex("(100+1+|01)+")) ? "SUBMARINE" : "NOISE") << '\n';
	return 0;
}
