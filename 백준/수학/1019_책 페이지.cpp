//
//  1019_책 페이지.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/03/23.
//  Copyright © 2020 장우진. All rights reserved.
//
/*
 문제: [a,b]사이에 존재하는 모든 정수에 있는 0~9 숫자의 출현 횟수를 구하는 문제.
 해설: a의 첫째 자리 수는 무조건 0으로 올려주고, b의 첫째 자리 수는 무조건 9로 내려준다.
	  여기서 a를 올려줄 때 a와 b가 같게 되면 종료함에 유의한다. 이 과정에서 각 자리의 숫자들을 따로
	  더해준다. 1의 자리부터 시작하여 b의 최대 자리 수까지 반복하는데, 만일 x의 자리 수라면
	  구한 갯수에서 x를 곱해준다.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ans[10];

void calc(long long n, long long d) {
	while (n) {
		ans[n % 10] += d;
		n /= 10;
	}
}

int main() {
	long long a = 1, b, d = 1;
	cin >> b;
	while (a <= b) {
		while (a % 10 != 0 && a <= b)
			calc(a++, d);
		if (a > b) break;
		while (b % 10 != 9 && a <= b)
			calc(b--, d);
		long long cnt = b/10 - a/10 + 1;
		for (int i = 0; i < 10; ++i)
			ans[i] += cnt * d;
		a/=10; b/=10; d*=10LL;
	}
	for (int i = 0; i < 10; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
