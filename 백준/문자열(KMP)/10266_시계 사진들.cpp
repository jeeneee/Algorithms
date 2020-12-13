//
//  10266_시계 사진들.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/06.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 해싱 + KMP
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 360000;

vector<int> getPartialMatch(const vector<bool>& N) {
	vector<int> pi(MAX, 0);
	int matched = 0;
	for (int i = 1; i < MAX; i++){
		while (matched > 0 && N[i] != N[matched])
			matched = pi[matched - 1];
		if (N[i] == N[matched])
			pi[i] = ++matched;
	}
	return pi;
}

bool isPossible(const vector<bool>& H, const vector<bool>& N) {
	vector<int> pi = getPartialMatch(N);
	int matched = 0;
	for (int i = 0; i < 2*MAX; ++i) {
		while (matched > 0 && H[i] != N[matched]) {
			matched = pi[matched-1];
		}
		if (H[i] == N[matched]) {
			if (matched == MAX - 1)
				return true;
			else ++matched;
		}
	}
	return false;
}

int main() {
	vector<bool> H(2 * MAX, 0);
	vector<bool> N(MAX, 0);
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		H[x] = 1;
		H[x + MAX] = 1;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		N[x] = 1;
	}
	
	if (isPossible(H, N))
		printf("possible\n");
	else
		printf("impossible\n");
	
	return 0;
}
