//
//  [2020 카카오 인턴십] 수식 최대화.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/07/21.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long long solution(string expression) {
	long long answer = 0;
	vector<char> priorOp = {'*', '+', '-'};
	vector<long long> temp_num;
	vector<char> temp_op;
	string s = "";
	for (int i = 0; i < expression.size(); ++i) {
		if (!isdigit(expression[i])) {
			temp_num.push_back(stoi(s));
			s = "";
			temp_op.push_back(expression[i]);
		} else s += expression[i];
	}
	temp_num.push_back(stoi(s));
	do {
		vector<long long> num = temp_num;
		vector<char> op = temp_op;
		for (int i = 0; i < priorOp.size(); ++i) {
			for (int j = 0; j < op.size(); ++j) {
				if (op[j] == priorOp[i]) {
					if (priorOp[i] == '*')
						num[j] *= num[j+1];
					if (priorOp[i] == '+')
						num[j] += num[j+1];
					if (priorOp[i] == '-')
						num[j] -= num[j+1];
					num.erase(num.begin() + j + 1);
					op.erase(op.begin() + j);
					--j;
				}
			}
		}
		answer = max(answer, abs(num[0]));
	} while (next_permutation(priorOp.begin(), priorOp.end()));
    return answer;
}

int main() {
	string expression = "100-200*300-500+20";
	cout << solution(expression) << endl;
	return 0;
}
