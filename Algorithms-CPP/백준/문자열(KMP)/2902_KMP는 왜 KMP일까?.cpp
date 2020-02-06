//
//  2902_KMP는 왜 KMP일까?.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s, ans = "";
	cin >> s;
	for (char& c : s) {
		if ('A' <= c && c <= 'Z')
			ans += c;
	}
	cout << ans << endl;
	return 0;
}
