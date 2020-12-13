//
//  1132_합.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/21.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: A~J 10개의 알파벳이 숫자 대신 주어진다. 이에 숫자를 대입해 합이 가장 큰 수를 구하는 문제.
	  백트래킹을 이용한 <1339_단어 수학>에서 8자리 수에 10개였던 것이 12자리 수에 50개로 늘어나서
	  백트래킹을 쓸 수 없다. 다항식을 이용한다.
 해설: 맨 앞자리가 0이 올 수 없기 때문에 입력을 받을 때 미리 저장해준다. 그런 다음 정렬을 하고 맨 앞자리가
	  0일 경우 뒤로 보내준다.
 알고리즘: 수학 다항식 정렬
 */
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string str[n];
	bool single[10];
	vector<pair<long long, int>> num(10);
	for (int i = 0; i < 10; ++i) {
		single[i] = false;
		num[i].second = i;
	}
	
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		single[str[i][0] - 'A'] = true;
		for (int j = 0; j < str[i].size(); ++j)
			num[str[i][j] - 'A'].first += (long long)pow(10.0, str[i].size()-j-1);
	}
	sort(num.begin(), num.end());
	
	int i = 1;
	while (single[num[0].second]) swap(num[0], num[i++]);
	
	long long ans = 0;
	for (int i = 0; i < 10; ++i)
		ans += i * num[i].first;
	cout << ans << '\n';
	return 0;
}
