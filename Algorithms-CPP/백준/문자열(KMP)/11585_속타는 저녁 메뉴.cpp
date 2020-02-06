//
//  11585_속타는 저녁 메뉴.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/06.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 41행 i+1임에 유의한다. 한 바퀴가 돌기 전에 끝나야 한다.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

vector<int> getPartialMatch(const string& N) {
	int n = (int)N.size();
	vector<int> pi(n, 0);
	int j = 0;
	for (int i = 1; i < n; ++i) {
		while (j > 0 && N[i] != N[j])
			j = pi[j-1];
		if (N[i] == N[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
	vector<int> pi = getPartialMatch(N);
	vector<int> ret;
	int n = (int)H.size();
	int m = (int)N.size();
	int matched = 0;
	
	for (int i = 0; i+1 < n; ++i) {
		while (matched > 0 && H[i] != N[matched])
			matched = pi[matched-1];
		if (H[i] == N[matched]) {
			++matched;
			if (matched == m) {
				ret.push_back(i - m + 1);
				matched = pi[matched-1];
			}
		}
	}
	return ret;
}

int main() {
	int n;
	char c;
	string H, N;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c", &c);
		H += c;
	}
	H += H;
	for (int i = 0; i < n; ++i) {
		scanf(" %c", &c);
		N += c;
	}
	
	int res = (int)kmpSearch(H, N).size();
	int g = gcd(res, n);
	printf("%d/%d\n", res/g, n/g);
	
	return 0;
}
