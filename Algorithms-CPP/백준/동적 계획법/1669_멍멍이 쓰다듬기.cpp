//
//  1669_멍멍이 쓰다듬기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/20.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 규칙을 찾는 문제. 연습장에 몇 개 써보면 알아낼 수 있다. num이 int 범위를 초과할 수 있음에 유의한다.
 */
#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int d = 0;
	unsigned num = 0;
	while (num < y-x) {
		d++;
		num += (d+1) / 2;
	}
	cout << d << endl;
	return 0;
}
