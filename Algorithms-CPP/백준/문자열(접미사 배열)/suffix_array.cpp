//
//  suffix_array.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/02/06.
//  Copyright © 2020 장우진. All rights reserved.
//

#include<cassert>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 두 접미사의 시작 위치 i, j 가 주어질 때 두 접미사 중 어느 쪽이 앞에 와야 할 지 비교한다
struct SuffixComparator {
	const string& s;
	SuffixComparator(const string& s) : s(s) {}
	bool operator () (int i, int j) {
		// s.substr() 대신에 strcmp() 를 쓰면 임시 객체를 만드는 비용이 절약된다
		return strcmp(s.c_str() + i, s.c_str() + j) < 0;
	}
};

// O(N^2logN)
// s 의 접미사 배열을 계산한다
vector<int> getSuffixArrayNaive(const string& s) {
	// 접미사 시작 위치를 담은 배열을 만든다
	vector<int> perm;
	for(int i = 0; i < s.size(); i++) perm.push_back(i);
	// 접미사를 비교하는 비교자를 이용해 정렬하면 완성!
	sort(perm.begin(), perm.end(), SuffixComparator(s));
	return perm;
}

// 각 접미사들의 첫 t 글자를 기준으로 한 그룹 번호가 주어질 때,
// 주어진 두 접미사를 첫 2*t 글자를 기준으로 비교한다.
struct Comparator {
	const vector<int>& group;
	int t;
	
	Comparator(const vector<int>& _group, int _h) : group(_group), t(_h) { }
	
	bool operator () (int a, int b) {
		// 첫 t 글자가 다르면 이들을 이용해 비교한다
		if(group[a] != group[b]) return group[a] < group[b];
		// 아니라면 S[a+t..] 와 S[b+t..] 의 첫 t 글자를 비교한다
		return group[a + t] < group[b + t];
	}
};


// 맨버-마이어스의 알고리즘 O(Nlg^2N)
// s 의 접미사 배열을 계산한다
vector<int> getSuffixArray(const string& s) {
	int n = (int)s.size();
	
	// group[i] = 접미사들을 첫 t 글자를 기준으로 정렬했을 때,
	//            S[i..] 가 들어가는 그룹 번호.
	// t = 1 일 때는 정렬할 것 없이 S[i..] 의 첫 글자로 그룹 번호를 정해 줘도
	// 같은 효과가 있다.
	int t = 1;
	vector<int> group(n+1);
	for(int i = 0; i < n; i++) group[i] = s[i];
	group[n] = -1;
	
	// 결과적으로 접미사 배열이 될 반환값. 이 배열을 lg(n) 번 정렬한다.
	vector<int> perm(n);
	for(int i = 0; i < n; i++) perm[i] = i;
	
	while(t < n) {
		// group[] 은 첫 t 글자를 기준으로 계산해 뒀다.
		// 첫 2t 글자를 기준으로 perm 을 다시 정렬한다
		Comparator compareUsing2T(group, t);
		sort(perm.begin(), perm.end(), compareUsing2T);
		
		// 2t 글자가 n 을 넘는다면 이제 접미사 배열 완성!
		t *= 2;
		if(t >= n) break;
		
		// 2t 글자를 기준으로 한 그룹 정보를 만든다
		vector<int> newGroup(n+1);
		newGroup[n] = -1;
		newGroup[perm[0]] = 0;
		for(int i = 1; i < n; i++)
			if(compareUsing2T(perm[i-1], perm[i]))
				newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
			else
				newGroup[perm[i]] = newGroup[perm[i-1]];
		group = newGroup;
	}
	return perm;
}

int main() {
	string s;
	while(cin >> s) {
		vector<int> perm = getSuffixArray(s);
		for(int i = 0; i < perm.size(); i++)
			printf("%d: %s\n", perm[i], s.c_str() + perm[i]);
	}
	return 0;
}

