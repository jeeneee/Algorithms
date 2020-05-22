//
//  [2019 카카오 개발자 겨울 인턴십] 호텔 방 배정.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/22.
//  Copyright © 2020 장우진. All rights reserved.
//
// Hashmap + disjoint-set
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> m;

long long find(long long x) {
	if (!m[x]) return x;
	return m[x] = find(m[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
	vector<long long> answer;
	m.clear();
	for (long long num : room_number) {
		if (!m[num]) {
			answer.push_back(num);
			m[num] = find(num+1);
		} else {
			long long temp = find(num);
			answer.push_back(temp);
			m[temp] = find(temp+1);
//			m[num] = m[temp] = find(temp+1);
		}
	}
	return answer;
}

int main() {
	vector<long long> room_number = {1,3,4,1,3,1};
	long long k = 10;
	for (auto& a : solution(k, room_number))
		cout << a << ' ';
	cout << endl;
	return 0;
}
