//
//  Winter Coding(~2018)] 소수 만들기.cpp
//  Algorithms-CPP
//
//  Created by 장우진 on 2020/05/18.
//  Copyright © 2020 장우진. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 3001;

int solution(vector<int> nums) {
    bool isPrime[MAX];
    for (int i = 2; i < MAX; ++i) isPrime[i] = true;
    for (int i = 2; i*i <= MAX; ++i)
        if (isPrime[i])
            for (int j = i*i; j <= MAX; j += i)
                isPrime[j] = false;
    int n = nums.size();
    int answer = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            for (int k = j+1; k < n; ++k)
                if (isPrime[nums[i] + nums[j] + nums[k]])
                    ++answer;
    return answer;
}

int main() {
	vector<int> nums = {1,2,3,4};
	cout << solution(nums) << endl;
	return 0;
}
