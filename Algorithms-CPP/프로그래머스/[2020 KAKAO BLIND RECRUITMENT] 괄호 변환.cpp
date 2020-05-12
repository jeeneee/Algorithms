//
//  [2020 KAKAO BLIND RECRUITMENT] 괄호 변환.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/12.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string& s) {
	stack<char> st;
	for (char& c : s) {
		if (c == '(') st.push(c);
		else {
			if (st.empty()) return false;
			else st.pop();
		}
	}
	if (st.empty()) return true;
	else return false;
}

string solution(string p) {
	// 1
	if (p.empty()) return p;
	string u = "";
	string v = "";
	int open = 0, close = 0;
	for (int i = 0; i < p.size(); ++i) {
		u += p[i];
		(p[i] == '(') ? ++open : ++close;
		// 2
		if (open == close) {
			v = p.substr(i+1, p.size()-i);
			// 3
			if (isCorrect(u)) {
				return u + solution(v);
			} else {
				string ret = "";
				ret += "("; // 4-1
				ret += solution(v); // 4-2
				ret += ")"; // 4-3
				// 4-4
				for (int i = 1; i < u.size()-1; ++i) {
					if (u[i] == '(') ret += ")";
					else ret += "(";
				}
				return ret; // 4-5
			}
		}
	}
	return u;
}

int main() {
	vector<string> p = {
		"(()())()",
		")(",
		"()))((()"
	};
	for (auto& a : p)
		cout << solution(a) << endl;
	return 0;
}
